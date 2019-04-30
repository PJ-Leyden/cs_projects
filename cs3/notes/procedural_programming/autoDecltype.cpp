// demonstrates the use of auto and decltype
// Mikhail Nesterenko
// 6/10/2014

#include <iostream>

using std::cout; using std::endl;

int main(){

   int i = 5;
   auto j = i + 5.5; 
   decltype(j+5) k; 
   k = i + j;
   cout << i << " " << j << " " << k << endl;
}
