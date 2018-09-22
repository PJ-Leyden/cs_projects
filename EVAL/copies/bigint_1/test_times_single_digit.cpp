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
        bi = bi.times_single_digit(1);  //Or whatever you call it.

        // Verify
        assert(bi == 12);  //WRong add test cases.
    }


    //Add test cases as needed.
    
    std::cout << "Done testing bigint * single digit" << std::endl;

