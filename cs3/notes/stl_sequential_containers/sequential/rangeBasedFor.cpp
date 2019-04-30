// range-based for, C++11
// Mikhail Nesterenko
// 3/10/2014

#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::cout; using std::endl; 


int main(){
   std::deque<int> v = {10,20,30,40};

   // use reference if modifying elements 
   // "auto" -- automatically determine type
   for(auto &e: v) e-=3; 
                         

   for(auto e: v) 
       cout << e << " ";
   cout << endl;
}
