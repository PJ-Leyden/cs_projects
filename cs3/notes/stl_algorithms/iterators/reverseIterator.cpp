// reverse iterator
// Mikhail Nesterenko
// 4/8/2014

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main() {
   srand(static_cast<unsigned>(time(nullptr)));
   vector<int> v(rand() % 30);
   generate(v.begin(), v.end(), [](){return rand()%10;});
   cout << "Elements in vector: ";  
   for(auto e : v) cout << e << ' '; cout << endl;

   cout << "Enter a number to find: "; 
   int num; 
   cin >> num;

   cout << "found it at position(s): ";
   for(auto it = find(v.begin(), v.end(), num); 
       it != v.end();
       it = find(++it, v.end(), num)
       )
      cout << it - v.begin() << ' ';
   cout << endl;

   cout << "looking from back found it at position: ";
   for(auto rit = find(v.rbegin(), v.rend(), num);
       rit != v.rend();
       rit = find(++rit, v.rend(), num)
       )
      cout << rit.base() - 1 - v.begin() << ',' 
	   << rit - v.rbegin() << ' ';
   cout << endl;
}
