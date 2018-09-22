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
        String str;
        String str1;

        // VERIFY
        assert(str == str1);    
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str('a');
        String str1('a');

        // VERIFY
        assert(str == str1);    
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str('a');
        String str1('b');

        // VERIFY
        assert(!(str == str1));    
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str("abcd");
        String str1("abcd");

        // VERIFY
        assert(str == str1);    
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str("abcd");
        String str1("abc");

        // VERIFY
        assert(!(str == str1));    
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char temp1[] = "abcd";
        char temp2[] = "abcd";

        String str(temp1);
        String str1(temp2);

        // VERIFY
        assert(str == str1);    
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char temp1[] = "abcd";
        char temp2[] = "efgh";

        String str(temp1);
        String str1(temp2);

        // VERIFY
        assert(str != str1);    
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing equals." << std::endl;
}

