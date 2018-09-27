//  bigint Test Program
//
//  Tests:  C-string constructor and operator<<, uses ==
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
        bigint bi("0");

        // Verify
        assert(bi == 0);        
    }

    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test 
        bigint bi("1");

        // Verify
        assert(bi == 1);
    }

    {
        //------------------------------------------------------
        // Test: Construct with two-digit value
        // Setup fixture

        // Test 
        bigint bi("27");

        // Verify
        assert(bi == 27);
    }

    {
        //------------------------------------------------------
        // Test: Construct with six-digit value
        // Setup fixture

        // Test 
        bigint bi("456789");

        // Verify
        assert(bi == 456789);
    }
    

    {
        //------------------------------------------------------
        // Test: Construct with value that greater than an int will hold
        // Setup fixture
        // Larger than max int so need to check manually.

        // Test 
        bigint bi("6234567890");
    
        // Verify
        assert(bi == "6234567890");

        bi = bigint("62345");   //Check re-assignment.
        assert(bi == "62345");


    }

    {
        //------------------------------------------------------
        // Test: Output
        // Setup fixture
        // Larger than max int so need to check manually.

        // Test
        bigint bi("12345678901234567890123456789012345678901234567890123456789012345678901234567890");

        // Verify
        assert(bi == "12345678901234567890123456789012345678901234567890123456789012345678901234567890");

    }

    std::cout << "Done testing constructor bigint(char[])." << std::endl;

}

