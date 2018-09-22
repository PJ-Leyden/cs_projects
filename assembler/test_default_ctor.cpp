//File: test_default_ctro.cpp
//Author: P.J. Leyden
//Date: April 2nd, 2016

#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "string/string.hpp"

int main(){
	{
		Stack<int> stk;
		assert(stk.isEmpty());
	}

	//=================================================

	{
		Stack<String> stk;
		assert(stk.isEmpty());
	}

	//=================================================

	std::cout<<"Finished Testing Default Constructor\n";
	return 0;
}