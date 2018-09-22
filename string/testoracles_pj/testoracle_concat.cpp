//  String class test program
//
//  Name: P.J. Leyden 
//  Tests: Concationation Test
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
        String  left("abcd");
        String  right("efgh");

        // TEST
        String result = (left + right);
        // VERIFY
        assert(result == "abcdefgh");
        assert(left   == "abcd");
        assert(right  == "efgh");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right;

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "");
        assert(left   == "");
        assert(right  == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("");
        String  right("abcd");

        // TEST
        String result = (left + right);

        // VERIFY
        std::cerr<<"Length left == "<<left.length()<<'\n';
        std::cerr<<"Length right == "<<right.length()<<'\n';
        std::cerr<<result<<'\n';
        assert(result == "abcd");
        assert(left   == "");
        assert(right  == "abcd");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcd");
        String  right("");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "abcd");
        assert(left   == "abcd");
        assert(right  == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left('P');
        String  right('J');

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "PJ");
        assert(left   == 'P');
        assert(right  == 'J');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //String  left(X);
        //String  right(X);

        // TEST
        //RESULT_TYPE result = (left OP right);

        // VERIFY
        //assert(result == X);
        //assert(left   == X);
        //assert(right  == X);
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing +." << std::endl;
}

