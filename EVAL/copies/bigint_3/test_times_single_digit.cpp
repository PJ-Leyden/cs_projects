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
        bi = timesDigit(bi, 4);
        // Verify
        assert(bi == 12);
    }

    {
        bigint bi(256);

        bi = timesDigit(bi, 9);

        std::cerr<<256 * 9<<std::endl;
        std::cerr<<bi<<std::endl;
    }

    {
        bigint bi("45648894994004664783778798798798");

        bi = timesDigit(bi, 9);

        std::cerr<<bi<<std::endl;
    }



    //Add test cases as needed.
    
    std::cout << "Done testing bigint * single digit" << std::endl;
}
