//==============================================================================
// Basics for openning a file for Part 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-1.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }
    bigint bi1;
    bigint bi2;
    
    in >> bi1;
    in >> bi2;

    std::cout<<"bi1 == "<<bi1<<std::endl;
    std::cout<<"bi2 == "<<bi2<<std::endl;

    bigint bi3;

    bi3 = bi1 + bi2;

    std::cout<<"bi3 == "<<bi3<<std::endl;

    //Until end of file
       //Read two bigints
       //Print them out
       //Add them together
       //Print out results
 
    in.close();
    return 0;
}

