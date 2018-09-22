// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    //=======================================================================
    {
        bigint temp;
        //std::cout<<"The Length is: "<<temp.length()<<std::endl;
        bigint bi(44567);
        bi = timesDigit(bi, 8);
       // std::cout<<bi<<" == "<<44567 * 8<<std::endl;
    }
    //=======================================================================
    {
        bigint bi(35);
       // std::cout<<bi<<std::endl;
        // Test 
        bi = timesTen(bi, 4);
       // std::cout<<bi<<std::endl;
        // Verify
        assert(bi == 350000);   
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times10" << std::endl;

    {
        bigint bi(12345);
        bigint bi1(123);
        bigint bi2;

        bi2 = bi * bi1;

        std::cout<<bi2<<" == "<<12345*123<<std::endl;

    }
}

