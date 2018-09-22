//  String class test program
//
//  Tests: XXX
//

#include <string.hpp>
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str;

        // VERIFY
        assert(str == '\0');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str;

        // VERIFY
        assert('\0' == str);
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Default Ctor." << std::endl;

}

