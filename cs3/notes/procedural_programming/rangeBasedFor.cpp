// demonstrates range-based-for
// Mikhail Nesterenko
// 6/10/2014

#include <iostream>
using std::cout; using std::endl;

int main(){

   int a[] = {10, 20, 30, 40, 50, 60};
   
   for(auto &e: a)
      e+=5;
   
   for(auto e: a) // printing them out
      cout << e << endl;
}
