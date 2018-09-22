//  String class test program
//
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(9);
        // VERIFY
        assert(str.capacity() == 9);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(1);

        // VERIFY
        assert(str.capacity() == 1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(2578);

        // VERIFY
        assert(str.capacity() == 2578);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Int ctor." << std::endl;

}

