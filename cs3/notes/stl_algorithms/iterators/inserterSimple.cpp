// demonstrates using insert iterator without algorithms
// Mikhail Nesterenko
// 3/24/2019

#include <iostream>
#include <vector>

using std::cout; using std::endl;

int main(){
   std::vector <int> v;

   auto it = inserter(v, v.begin());

   for(int i=0; i < 10; ++i)
      *it = i;

   for(auto e: v) cout << e << ' '; cout << endl;
}
