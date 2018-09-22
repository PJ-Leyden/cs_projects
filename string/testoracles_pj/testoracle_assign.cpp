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
        String  str("");

        // TEST
        String cpy = str;

        // VERIFY
        assert(str == cpy);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;

        // TEST
        String cpy = str;

        // VERIFY
        assert(str == cpy);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcd");

        // TEST
        String cpy = str;

        // VERIFY
        assert(str == cpy);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str('\0');

        // TEST
        String cpy = str;

        // VERIFY
        assert(str == cpy);
    }

    { 
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("1234 5678");

        // TEST
        String cpy = str;

        // VERIFY
        assert(str == cpy);
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    std::cout << "Done testing =." << std::endl;

}

