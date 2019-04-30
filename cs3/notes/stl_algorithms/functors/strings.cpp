// using plus<string>
// Mikhail Nesterenko
// 2/27/2019

#include <vector>
#include <iostream>
#include <string>
#include <numeric>

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::string;


int main() {
   vector<string> vect = {"one", "two", "three"};

   string result = accumulate(vect.begin(), vect.end(), 
			      string(""), std::plus<string>());

   cout << result << endl;
}
