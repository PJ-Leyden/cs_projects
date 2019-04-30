// back inserter with move
// Mikhail Nesterenko
// 10/01/2014

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::endl;
using std::vector; using std::string;

int main() {
   vector<string> v, w;
   v.push_back("one"); 
   v.push_back("two"); 
   v.push_back("three"); 
   v.push_back("four"); 
   v.push_back("five");

   move(v.begin(), v.end(), std::back_inserter(w));

   cout << "Contents of source vector: ";
   for(auto &s: v) cout << s << ", "; cout << endl;

   cout << "Contents of target vector: ";
   for(auto &s: w) cout << s << ", "; cout << endl;
}

