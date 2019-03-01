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
        bi = bi.times_10(0);

        // Verify
        assert(bi == 77);  //Wrong. Will FAIL, fix and add tests cases
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
}

