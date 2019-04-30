// back insert iterator
// Mikhail Nesterenko
// 4/8/2014

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::back_inserter;


int main() {
   srand(static_cast<unsigned>(time(nullptr)));
   /*
   vector<int> v(rand() % 10);
   generate(v.begin(), v.end(), [](){return rand()%10;});
   */

   vector<int> v;
   generate_n(inserter(v, v.begin()), rand() % 10, 
	           []{return rand()%10;});

   cout << "elements in vector v: ";  
   for(auto e : v) cout << e << ' '; cout << endl;

   // copy vector into empty vector with back_insert iterator
   vector<int> u;
   std::back_insert_iterator<vector<int>> bit(u);
   copy(v.begin(), v.end(), bit);

   cout << "copied vector: ";
   for(auto e: u) cout << e << ' '; cout << endl;

   v.clear();


   copy_if(u.begin(), u.end(), 
	   back_inserter(v), 
	   [](int i){return i > 5;});


   cout << "copied elements greater than 5: ";
   for(auto e: v) cout << e << ' '; cout << endl;

   // using transform
   vector <int> w; // new empty vector


   transform(v.begin(), v.end(), 
	     u.begin(), 
	     back_inserter(w),
	     [](int a, int b){return a+b;});

   cout << "transformed elements: ";
   for(auto e: w) cout << e << " "; cout << endl;

}
