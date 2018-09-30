// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  
        assert(digit == 4);
    }
    
    {
        // Setup
        bigint bi;

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 0);  
        assert(digit == 0);
    }

    {
        // Setup
        bigint bi(524563);

        // Test 
        int digit1 = bi[0];
        int digit2 = bi[1];
        int digit3 = bi[4];

        // Verify
        assert(bi    == 524563);  
        assert(digit1 == 3);
        assert(digit2 == 6);
        assert(digit3 == 2);
    }

    std::cout << "Done testing subscript." << std::endl;
}

