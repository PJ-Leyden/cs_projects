//File: test_pop.cpp
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
		int temp = stk.pop();
		assert(temp == 12);
	}

	//=================================================

	{
		Stack<int> stk;
		assert(stk.isEmpty());

		int temp = 39;
		stk.push(temp);
		int out = stk.pop();
		assert(out == 39);
		assert(out == temp);
	}

	//=================================================

	{
		Stack<String> stk;
		assert(stk.isEmpty());

		stk.push("Hello");
		String temp = stk.pop();
		assert(temp == "Hello");
	}

	//=================================================

	{
		Stack<String> stk;
		assert(stk.isEmpty());

		String temp("Hello");
		stk.push(temp);
		String out = stk.pop();
		assert(out == "Hello");
		assert(out == temp);
	}

	//=================================================

	std::cout<<"Finished Testing Pop\n";
	return 0;
}