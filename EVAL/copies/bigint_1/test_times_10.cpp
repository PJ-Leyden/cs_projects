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
        bi = bi.times10(0); //Or whatever you call it.

        // Verify
        assert(bi == 77);  //Wrong.  Add tests cases
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times10" << std::endl;
}

