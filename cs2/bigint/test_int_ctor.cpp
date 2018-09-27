// bigint Test Program
//
// Tests:  int constructor and output << operator.
//         uses ==
// 
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        //------------------------------------------------------
        // Test: Construct with 0
        // Setup fixture

        // Test 
        bigint bi(0);

        // Verify
        assert(bi == 0);
        
    }

    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test 
        bigint bi(1);

        // Verify
        assert(bi == 1);
        
    }

    {
        //------------------------------------------------------
        // Test: Construct with 100000
        // Setup fixture

        // Test 
        bigint bi(100000);
        // Verify
        assert(bi == 100000);
        
    }


    {
        //------------------------------------------------------
        // Test: Construct with two-digit value
        // Setup fixture

        // Test 
        bigint bi(27);

        // Verify
        assert(bi == 27);

        // Verify
        bi = bigint(5006);   //Check re-assignment.
        assert(bi == 5006);
    }

    {
        //------------------------------------------------------
        // Test: Construct with six-digit value
        // Setup fixture

        // Test 
        bigint bi(456789);

        // Verify
        assert(bi == 456789);    }
    
    std::cout << "Done testing constructor bigint(int)." << std::endl;


}

