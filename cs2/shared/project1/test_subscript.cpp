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
        assert(bi    == 800);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 250);
    }
    
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
}

