// demonstrates sort, merge, binary_search, unique, binary_search, random_shuffle
// Mikhail Nesterenko
// 04/01/2014

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

using std::cout; using std::endl;
using std::vector; using std::string;

int main() {
   vector<int> u, v, w;
   
   srand(unsigned(time(nullptr)));

   u.resize(rand()%15);
   v.resize(rand()%15);

   generate(u.begin(), u.end(), []{return rand()%10;});
   generate(v.begin(), v.end(), []{return rand()%10;});

   cout << "contents of u: "; 
   for(auto e: u) cout << e << " "; cout << endl;
   cout << "contents of v: "; 
   for(auto e: v) cout << e << " "; cout << endl;
 
   sort(u.begin(), u.end());
   sort(v.begin(), v.end());

   cout << "sorted u: "; 
   for(auto e: u) cout << e << " "; cout << endl;
   cout << "sorted v: "; 
   for(auto e: v) cout << e << " "; cout << endl;

   w.resize(u.size()+v.size());

   merge(u.begin(), u.end(), 
	 v.begin(), v.end(), 
	 w.begin());
 
   cout << "contents of w: "; 
   for(auto e: w) cout << e << " "; cout << endl;


   w.erase(unique(w.begin(), w.end()), w.end());

   cout << "w with duplicates removed: ";
   for(auto e: w) cout << e << " "; cout << endl;
 
   int pick=rand()%10;

   if(auto found=binary_search(w.begin(), w.end(), pick))
      cout << pick << " is found" <<  endl;
   else
      cout << pick << " not found" << endl;


   sort(w.begin(), w.end(), std::greater<int>());

   cout << "w sorted in descending order: "; 
   for(auto e: w) cout << e << " "; cout << endl;


   random_shuffle(w.begin(), w.end());
   cout << "w reshuffled: "; for(auto e: w) cout << e << " "; cout << endl;
 
}
