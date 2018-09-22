//File: postfix.cpp
//Author: P.J. Leyden
//Date: April 7th, 2016

#include <iostream>
#include <fstream>
#include <cassert>
#include "../string/string.hpp"
#include "../assembler/stack.hpp"
//=================================
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
//=================================
int main(int argc, char* argv[]){

	std::ifstream in(argv[1]);
	if(!in){std::cerr<<"Couldn't open\n";}

	std::vector<String> express = parse(in);

	in.close();
	//============================================
	std::ofstream writer;
	if(argc == 3){writer.open(argv[2]);}
	else{writer.open("output.txt");}

	writer<<"Infix to Postfix Expressions:\n//===========================\n";
	for(int i = 0; i < (int)express.size() - 1; ++i){
		String infix = express[i];
		String postfix = toPostfix(express[i]);
		writer<<(i + 1)<<") Infix: "<<infix<<'\n';
		writer<<"    Postfix: "<<postfix<<'\n';
	}
	writer<<"//===========================\n";
	writer.close();

	if(argc < 3){
		String x;
		std::ifstream out("output.txt");
		std::vector<String> toPrint = parse(out);
		for(int i = 0; i < (int)toPrint.size(); ++i){
			std::cout << toPrint[i] << '\n';
		}
		out.close();
	}
}
//======================================================