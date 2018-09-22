#include <iostream>
#include <cassert>
#include "bigint.hpp"
//===============================================
int main()
{
	{
		//Fixture
		bigint lhs = 0;
		bigint rhs = 0;
		bigint result;

		//Test
		result = lhs * rhs;

		//Verify
		assert(lhs == 0);
		assert(rhs == 0);
		assert(result == 0);
	}
}