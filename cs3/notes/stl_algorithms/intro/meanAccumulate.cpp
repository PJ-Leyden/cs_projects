// arithmetic/geometric mean using function pointers and lambads
// Mikhail Nesterenko, adopted from Prof. C++
// 3/29/2014

#include <numeric>
#include <vector>
#include <cmath>
#include <iostream>

using std::cout; using std::cin; 
using std::endl;
using std::vector;

// function to use as function pointer in accumulate()
int product(int num1, int num2){
   return num1 * num2;
}


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
   double sum = accumulate(vect.begin(),
			   vect.end(), 0);
   cout << sum/vect.size() << endl;

   cout << "The geometric mean is: "; 
   double mult = accumulate(vect.begin(),
	       vect.end(), 1, product);
   cout << pow(mult, 1.0/vect.size()) 
	<< endl;

   cout << "The geometric mean (Lambda version) is: ";
   double multLambda = 
    accumulate(vect.begin(), vect.end(), 1,
           [](int num1, int num2)
           { return num1 * num2; });
   cout <<  pow(multLambda, 1.0 / vect.size()) << endl;
}
