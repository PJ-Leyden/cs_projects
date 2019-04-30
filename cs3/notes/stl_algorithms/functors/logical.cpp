// comparison functors
// Mikhail Nesterenko, adopted from Prof. C++
// 3/29/2014

#include <numeric>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;


int main() {
   vector<bool> flags;

   cout << "Enter true/false, stop to stop: ";
   while (true) {
      string str;
      cin >> str;
      if (str[0] == 's') break;
      flags.push_back(str[0]=='t');
   }

  

   bool allTrue=accumulate(flags.begin(), flags.end(), true,
			   std::logical_and<bool>());

   if(allTrue) cout << "All true" << endl;
   
   bool anyTrue=accumulate(flags.begin(), flags.end(), false,
			   std::logical_or<bool>());
   if(anyTrue) cout << "Some true" << endl;
}
