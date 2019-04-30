// demonstrates back inserter to compute set union
// Mikhail Nesterenko
// 10/11/2014

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
  
   vector<int> w;
   set_union(u.cbegin(), u.cend(), 
	     v.cbegin(), v.cend(),
	     back_inserter(w));


   cout << "set union: ";
   for(auto e: w) cout << e << " "; cout << endl;

}
