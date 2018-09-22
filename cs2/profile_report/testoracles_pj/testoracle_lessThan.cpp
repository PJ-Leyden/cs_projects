//  String class test program
//
//  Name:  P.J. Leyden
//  Tests: <
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
        String  left('b');
        String  right('a');

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "b");
        assert(right  == "a");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcd");
        String  right("ABCD");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "abcd");
        assert(right  == "ABCD");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("A");
        String  right("B");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(left   == "A");
        assert(right  == "B");
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing <." << std::endl;
}

