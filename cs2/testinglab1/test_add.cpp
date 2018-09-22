#include "super_math.hpp"
#include <cassert>

int main()
{
	{
		//Ficture
		int lhs = 0;
		int rhs = 0;
		int result;

		//Test
		result = super_math::add(lhs, rhs);
		
		//Verify
		assert(lhs == 0);
		assert(rhs == 0);
		assert(result == 0);

	}
	return 0;
}

