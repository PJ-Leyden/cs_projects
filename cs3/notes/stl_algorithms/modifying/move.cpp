// demonstrates move, C++11
// Mikhail Nesterenko
// 04/01/2014

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::endl;
using std::vector; using std::string;

int main() {
   vector<string> v, w;
   v.push_back("one"); v.push_back("two"); 
   v.push_back("three"); 
   v.push_back("four"); v.push_back("five");
 
   w.resize(v.size());

   move(v.begin(), v.end(), w.begin());

   cout << "Contents of source vector: ";
   for(const auto &s: v) cout << s << ","; cout << endl;

   cout << "Contents of target vector: ";
   for(const auto &s: w) cout << s << ","; cout << endl;

   // move with move-assignment
   vector<string> u;
   u = move(w);
   cout << "Contents after move-assignment: ";
   for(const auto &s: u) cout << s << ","; cout << endl;


}
