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
        String  str(6, "abcd");
        String  str1("abcd");

        // VERIFY
        assert(str == str1);
        assert(str.capacity() == 6);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(5,"");

        // VERIFY
        assert(str == "");
        assert(str.capacity() == 5);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(10, "a");

        // VERIFY
        assert(str == "a");
        assert(str.capacity() == 10);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing charArray Int ctor." << std::endl;

}

