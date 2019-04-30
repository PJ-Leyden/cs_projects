// using unique_ptr in STL
// Mikhail Nesterenko
// 10/24/2015

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using std::cout; using std::endl;
using std::unique_ptr;

bool sorter(const unique_ptr<int> &a, const unique_ptr<int> &b){return *a < *b;}


int main(){

   std::vector<unique_ptr<int>> v;


   // populating the vector 
   v.push_back(unique_ptr<int>(new int(3)));  
   v.push_back(unique_ptr<int>(new int(1)));
   v.push_back(unique_ptr<int>(new int(2)));


   std::sort(v.begin(), v.end(), sorter);  

   for(auto &e: v) cout << *e << ' '; cout << endl;
}
