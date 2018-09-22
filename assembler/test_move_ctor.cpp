//File: test_move_ctor.cpp
//Author: P.J. Leyden
//Date: April 2nd, 2016

#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "string/string.hpp"

template <typename T>
Stack<T> get_stack(Stack<T> copy){
	return copy;
}

int main(){
	/*{
		Stack<int> stk_copy();

		Stack<int> stk(new Stack<int>());
		assert(stk.isEmpty());
	}*/

	//=================================================

	{
		Stack<int> stk;
		assert(stk.isEmpty());

		stk.push(12);
		stk.push(0);
		stk.push(1);

		Stack<int>* temp = new Stack<int>(stk);
		Stack<int> stk2(*temp);

		int test1 = stk2.pop();
		int test2 = stk2.pop();
		int test3 = stk2.pop();

		assert(test1 == 1);
		assert(test2 == 0);
		assert(test3 == 12);
	}

	//=================================================

	{
		Stack<String>* temp = new Stack<String>();
		Stack<String> stk(*temp);
		assert(stk.isEmpty());
	}

	//=================================================

	{
		Stack<String> stk;
		assert(stk.isEmpty());

		stk.push("Hello");
		stk.push(" ");
		stk.push("World!");

		Stack<String>* temp = new Stack<String>(stk);
		Stack<String> stk2(*temp);

		String test1 = stk2.pop();
		String test2 = stk2.pop();
		String test3 = stk2.pop();

		assert(test1 == "World!");
		assert(test2 == " ");
		assert(test3 == "Hello");
	}

	//=================================================

	std::cout<<"Finished Testing Move Constr\n";
	return 0;
}