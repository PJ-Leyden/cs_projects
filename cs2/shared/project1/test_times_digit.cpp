// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times_digit(1);

        // Verify
        assert(bi == 12);  //Will FAIL, fix and add test cases.
    }


    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;

