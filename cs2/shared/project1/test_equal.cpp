// bigint Test Program
//
// Tests:   ==, uses bigint(int)
//
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(0);
        // Test 
        assert(bi == 0);
        // Verify
        std::cout << "0 == ";
        std::cout << bi;
        std::cout << std::endl;
    }
    
    {
        // Setup
        bigint bi1(1234);
        bigint bi2(1234);
        // Test
        assert(bi1 == bi2);
        // Verify
        std::cout << bi1;
        std::cout << " == ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    {
        // Setup
        bigint bi1(1234);
        bigint bi2(234);
        // Test
        assert(!(bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " != ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    {
        // Setup
        bigint bi1(1234);
        bigint bi2(123);
        // Test
        assert(!(bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " != ";
        std::cout << bi2;
        std::cout << std::endl;
    }
    {
        // Setup
        bigint bi1(123);
        bigint bi2(1234);
        // Test
        assert(!(bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " != ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    std::cout << "Done testing ==." << std::endl;
}

