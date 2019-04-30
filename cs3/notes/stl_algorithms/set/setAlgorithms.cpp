// demonstrates set algorithms
// Mikhail Nesterenko
// 04/01/2014

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

using std::cout; using std::endl;
using std::vector; using std::string;

int main() {
   vector<int> u, v;
   srand(unsigned(time(nullptr)));

   // generating sorting eliminating duplicates 
   // in two sets: u and v
   u.resize(rand()%15+1);
   v.resize(rand()%15+1);

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
  
   if(includes(u.cbegin(), u.cend(), 
	       v.cbegin(), v.cend()))
      cout << "u includes v" << endl;

   if(includes(v.cbegin(), v.cend(), 
	       u.cbegin(), u.cend()))
      cout << "v includes u" << endl;

   vector<int> w;
   w.resize(u.size()+v.size());

   auto tail=set_union(u.cbegin(), u.cend(), 
		       v.cbegin(), v.cend(),
		       w.begin());
   cout << "union of u and v: ";
   for_each(w.begin(), tail, 
	    [](int i){cout << i << " ";}); 
   cout << endl;

   tail=set_intersection(u.cbegin(), u.cend(), 
			 v.cbegin(), v.cend(),
			 w.begin());
   cout << "intersection of u and v: ";
   for_each(w.begin(), tail, 
	    [](int i){cout << i << " ";}); 
   cout << endl;

   tail=set_difference(u.cbegin(), u.cend(), 
		       v.cbegin(), v.cend(),
		       w.begin());
   cout << "elements that are in u but not in v: ";
   for_each(w.begin(), tail, 
	    [](int i){cout << i << " ";}); 
   cout << endl;

   tail=set_symmetric_difference(u.cbegin(), u.cend(), 
				 v.cbegin(), v.cend(),
				 w.begin());
   cout << "elements that are in u but not in v, or in v but not in u: ";
   for_each(w.begin(), tail, 
	    [](int i){cout << i << " ";}); 
   cout << endl;
}
