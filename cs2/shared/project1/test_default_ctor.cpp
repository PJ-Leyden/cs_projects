// bigint Test Program
//
// Tests:  default constructor, uses ==
//
//  
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    // Setup

    // Test 
    bigint bi;

    // Verify
    std::cout << "0 == " << bi << std::endl;
    assert(bi == 0);

    std::cout << "Done testing default constructor." << std::endl;
}

