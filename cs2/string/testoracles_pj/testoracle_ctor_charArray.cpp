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
        String  str("abcd");

        // VERIFY
        assert(str == "abcd");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("");

        // VERIFY
        assert(str == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("1234");

        // VERIFY
        assert(str == "1234");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("a");

        // VERIFY
        assert(str == 'a');
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing charArray ctor." << std::endl;

}

