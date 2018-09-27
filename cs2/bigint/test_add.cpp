// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(9);
      bigint right(9);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 9);
      assert(result == 18);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(49);
      bigint right(51);
      bigint result;

      // Test
      result = left + right;

      // Verify
      std::cout<<left<<" + "<<right<<" = "<<result<<std::endl;

      assert(left   == 49);
      assert(right  == 51);
      assert(result == 100);

      std::cout<<left<<" + "<<right<<" = "<<result<<std::endl;
    }

    //assert(1 == 2);   // You need to add some more test cases here.

    
    //Add test cases as needed.
    
    
    std::cout << "Done with testing addition." << std::endl;
}

