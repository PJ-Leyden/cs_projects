//  bigint Test Program
//
//  Tests:
//
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () 
{

    {
        //------------------------------------------------------
        // Test: Construct with 0
        // Setup fixture

        // Test 
        bigint bi("0");

        // Verify
        assert(bi == 0);        
    }
}
   