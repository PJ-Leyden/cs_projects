// demonstrates conversion string <-> integer
// Mikhail Nesterenko
// 6/11/2014

#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

int main(){

   // 
   // to integer conversion
   //
   const char* sOne = "123"; // C-style character array
   string sTwo = "321";      // C++ style strings

   int iOne = atoi(sOne);    // C-style string is converted directly
   int iTwo = atoi(sTwo.c_str()); // need to use c_str() with C++ style strings

   int iThree = stoi(sTwo); // C++11 preferred way of converting to string to int

   cout << iOne + iTwo + iThree << endl;

   //
   // to string conversion
   //
   string oneS = std::to_string(iOne); 
   string twoS = std::to_string(iTwo); 

   cout << oneS + twoS << endl;

}
