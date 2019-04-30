// arithmetic/geometric mean using functors
// Mikhail Nesterenko, adapted from Prof. C++
// 3/29/2014

#include <numeric>
#include <vector>
#include <cmath>
#include <iostream>
#include <functional>

using std::cout; using std::cin; using std::endl;
using std::vector;


int main() {
   vector<int> vect;

   cout << "Enter numbers (0 to stop): ";
   while (true) {
      int num;
      cin >> num;
      if (num==0) break;
      vect.push_back(num);
   }

   cout << "The arithmetic mean is: ";
   double sum = accumulate(vect.begin(), vect.end(), 0, 
			   std::plus<int>());
   cout << sum/vect.size() << endl;

   cout << "The geometric mean is: "; 
   double mult = accumulate(vect.begin(), vect.end(), 
			    1, std::multiplies<int>());
   cout << pow(mult, 1.0/vect.size()) << endl;
}
