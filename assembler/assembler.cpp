//File: assembler.cpp
//Author: P.J. Leyden
//Date: April 9th, 2016

#include <iostream>
#include <fstream>
#include <cassert>
#include "../string/string.hpp"
#include "../assembler/stack.hpp"
//==============================================
String toPostfix(String infix){
	String result = "";
	Stack<String> stk;
	std::vector<String> tokens = infix.split(' ');
	int indx = 0;
	while(tokens[indx] != ';'){
		if(tokens[indx] == '('){
			++indx;
		}else if(tokens[indx] == ')'){
			String rhs = stk.pop();
			String op = stk.pop();
			String lhs = stk.pop();
			String newToken = lhs + " " + rhs + " " + op;
			stk.push(newToken);
			++indx;
		}else{
			stk.push(tokens[indx]);
			++indx;
		}
	}
	result = stk.pop();
	return result;
}
//==============================================
String evaluate(String& left, String& op, String& right, std::ofstream& writer, int counter){//int counter = possible parameter

	writer <<"   " << "LD" << '\t' << " " << left << '\n';
	if(op == '/')     {writer << "   " << "DV" << '\t' << " " << right <<'\n';}
	else if(op == '*'){writer << "   " << "ML" << '\t' << " " << right <<'\n';}
	else if(op == '+'){writer << "   " << "AD" << '\t' << " " << right <<'\n';}
	else if(op == '-'){writer << "   " << "SB" << '\t' << " " << right <<'\n';}
	String adder((char)counter);
	String result = "TMP" + adder;//somehow add a counter...
	writer << "   " << "ST" << '\t' << " " << result << '\n';
	return result;
}
//==============================================
void toAssembly(String infix, std::ofstream& writer){
	writer << "Infix Expression: " << infix << '\n';
	String pstfx = toPostfix(infix);
	writer << "Postfix Expression: " << pstfx << '\n' << '\n';
	Stack<String> assembler;
	std::vector<String> pieces = pstfx.split(' ');
	/*
	for(int i = 0; i < (int)pieces.size(); ++i){
		std::cerr<<"["<<pieces[i]<<"]"<<'\n';
	}
	*/
	//==========================================
	int counter = 49;
	for(int i = 0; i < (int)pieces.size(); ++i){
		if((pieces[i] != '*') && (pieces[i] != '/') && (pieces[i] != '+') && (pieces[i] != '-')){
			assembler.push(pieces[i]);
		}else{
			String right = assembler.pop();
			String left = assembler.pop();
			assembler.push(evaluate(left, pieces[i], right, writer, counter));//counter = possible argument
			++counter;
		}
	} 
}
//==============================================
int main(int argc, char* argv[]){
	assert(argc >= 2);
	std::ifstream in(argv[1]);
	if(!in){std::cerr<<"Couldn't open\n"; return 0;}

	std::vector<String> express = parse(in);

	in.close();
	//============================================
	std::ofstream writer;
	if(argc >= 3){writer.open(argv[2]);}
	else if(argc == 2){writer.open("output.txt");}
	else{std::cerr<<"Need another argument"<<'\n';}
	
	for(int i = 0; i < (int)express.size() - 1; ++i){
		toAssembly(express[i], writer);
		writer << '\n';
	}

	writer.close();

	if(argc == 2){
		std::cerr<<"in the 2 thing~\n";
		std::ifstream out("output.txt");
		char ch;
		out.get(ch);
		while(!out.eof()){
			std::cout << ch;
			out.get(ch);
		}
		std::cout<< '\n';
		out.close();
	}

	return 0;
}