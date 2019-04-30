// set algorithms with inserters
// Mikhail Nesterenko
// 04/01/2014

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

using std::cout; using std::endl;
using std::vector; using std::string;
using std::back_inserter;

int main() {
   vector<int> u, v;
   srand(static_cast<unsigned>(time(nullptr)));

   // generating sorting eliminating 
   // duplicates in two sets: u and v

   u.resize(rand()%15);
   v.resize(rand()%15);

   generate(u.begin(), u.end(), []{return rand()%10;});
   generate(v.begin(), v.end(), []{return rand()%10;});

   sort(u.begin(), u.end());
   sort(v.begin(), v.end());

   u.erase(unique(u.begin(), u.end()), u.end());
   v.erase(unique(v.begin(), v.end()), v.end());


   cout << "set u: "; 
   for(auto e: u) cout << e << " "; cout << endl;
   cout << "set v: "; 
   for(auto e: v) cout << e << " "; cout << endl;
  
   if(includes(u.cbegin(), u.cend(), v.cbegin(), v.cend()))
      cout << "u includes v" << endl;

   if(includes(v.cbegin(), v.cend(), u.cbegin(), u.cend()))
      cout << "v includes u" << endl;

   vector<int> w;

   set_union(u.cbegin(), u.cend(), 
	     v.cbegin(), v.cend(),
	     back_inserter(w));

   cout << "union of u and v: ";
   for(auto e: w) cout << e << ' '; cout << endl;
   w.clear();

   set_intersection(u.cbegin(), u.cend(), 
		    v.cbegin(), v.cend(),
		    back_inserter(w));
   cout << "intersection of u and v: ";
   for(auto e: w) cout << e << ' '; cout << endl;
   w.clear();

   set_difference(u.cbegin(), u.cend(), v.cbegin(), v.cend(),
		       back_inserter(w));
   cout << "elements that are in u but not in v: ";
   for(auto e: w) cout << e << ' '; cout << endl;
   w.clear();

   set_symmetric_difference(u.cbegin(), u.cend(), v.cbegin(), v.cend(),
				 back_inserter(w));
   cout << "elements that are in u but not in v, or in v but not in u: ";
   for(auto e: w) cout << e << ' '; cout << endl;
   w.clear();
}
