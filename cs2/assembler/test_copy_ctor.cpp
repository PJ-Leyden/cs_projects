//File: test_copy_ctor.cpp
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

		Stack<int> stk2(stk);
		assert(stk2.isEmpty());
	}

	//=================================================

	{
		Stack<int> stk;
		assert(stk.isEmpty());

		stk.push(12);
		stk.push(0);
		stk.push(1);

		Stack<int> stk2(stk);

		int test1 = stk2.pop();
		int test2 = stk2.pop();
		int test3 = stk2.pop();

		assert(test1 == 1);
		assert(test2 == 0);
		assert(test3 == 12);
	}

	//=================================================

	{
		Stack<String> stk;
		assert(stk.isEmpty());

		Stack<String> stk2(stk);
		assert(stk2.isEmpty());
	}

	//=================================================

	{
		Stack<String> stk;
		assert(stk.isEmpty());

		stk.push("Hello");
		stk.push(" ");
		stk.push("World!");

		Stack<String> stk2(stk);

		String test1 = stk2.pop();
		String test2 = stk2.pop();
		String test3 = stk2.pop();

		assert(test1 == "World!");
		assert(test2 == " ");
		assert(test3 == "Hello");
	}

	//=================================================

	std::cout<<"Finished Testing Copy Constr\n";
	return 0;
}