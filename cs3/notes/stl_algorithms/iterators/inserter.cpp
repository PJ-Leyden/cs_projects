// insert iterator
// Mikhail Nesterenko
// 4/8/2014

#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <iterator>
#include <ctime>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::inserter;
using std::set;


int main() {
   srand(static_cast<unsigned>(time(nullptr)));
   vector<int> v(rand()%10);

   generate(v.begin(), v.end(), []{return rand()%10;});
   cout << "Elements in vector v: ";  
   for(auto e : v) cout << e << ' '; cout << endl;

   // copy vector into empty vector with insert iterator
   vector<int> u;
   std::insert_iterator<vector<int>> iit(u, u.begin());
   copy(v.begin(), v.end(), iit); // note u was empty

   cout << "copied vector: ";
   for(auto e: u) cout << e << ' '; cout << endl;

   vector<int> w(10);
   generate(w.begin(), w.end(), 
	    [](){return (rand()%10+1)*10;});
   
   // position iterator in the middle
   auto it = w.begin()+5; 

   // moving v into the middle of w
   move(v.begin(), v.end(), inserter(w, it));
   cout << "updated vector w: ";
   for(auto e: w) cout << e << ' '; cout << endl;

   // applying insert iterator to 
   // non-sequential containers (set)
   set<int> s;
   copy_if(w.begin(), w.end(), 
	   inserter(s, s.begin()), 
	            [](int i){return i > 5;});
   cout << "populated set: ";
   for(auto e: s) cout << e << ' '; cout << endl;

}
