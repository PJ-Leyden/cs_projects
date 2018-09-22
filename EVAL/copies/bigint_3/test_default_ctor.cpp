// bigint Test Program
//
// Tests:  default constructor, uses ==
//
//  
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    // Setup
    
    // Test 
    bigint bi;

	//std::cout<<bi<<std::endl;
	
    // Verify
    assert(bi == 0);
    
    std::cout << "0 == " << bi << std::endl;


    std::cout << "Done testing default constructor." << std::endl;
}
//==========================================================================
/*int main()
{//tested ==, <<, default 
	bigint bi1;
    bigint bi2;

    assert(bi1 == bi2);
    std::cout<<bi1;
    std::cout<<" == ";
    std::cout<<bi2;
    std::cout<<std::endl;



    bigint bi;
    bigint bi1(4567);
    std::cout<<bi<<" == "<<bi1<<std::endl;
    assert(!(bi == bi1));
    assert(bi == 0);
    std::cout<<"Finished"<<std::endl;

    //bigint bi("4567");
    //std::cout<<bi<<std::endl;
}*/