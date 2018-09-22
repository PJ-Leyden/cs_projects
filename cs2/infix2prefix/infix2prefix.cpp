//File: infix2prefix.cpp
//Author: P.J. Leyden
//Date: April 5th, 2016

#include <iostream>
#include <fstream>
#include <cassert>
#include "../string/string.hpp"
#include "../assembler/stack.hpp"

String toPrefix(String infix){
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
			String newToken = op + " " + lhs + " " + rhs;
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

int main(){
	{
		//============================================
		std::ifstream in("../assembler/data3-1.txt");
		if(!in){std::cerr<<"Couldn't open\n";}

		std::vector<String> infxExprs = parse(in);

		in.close();
		//============================================
		String firstLine = toPrefix(infxExprs[0]);
		std::cerr<<"Prefix of firstLine == "<<firstLine<<'\n';

		String firstLine1 = toPostfix(infxExprs[0]);
		std::cerr<<"Postfix of firstLine == "<<firstLine1<<'\n';
	}


	return 0;
}