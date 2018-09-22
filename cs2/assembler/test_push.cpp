//File: test_push.cpp
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

		stk.push(12);
		stk.push(0);

		int temp = 0;
		stk.push(temp);
	}

	//=================================================

	{
		Stack<String> stk;
		assert(stk.isEmpty());

		stk.push("Hello");
		stk.push(" ");

		String str = "World!";
		stk.push(str);
	}

	//=================================================

	std::cout<<"Finished Testing Push\n";
	return 0;
}