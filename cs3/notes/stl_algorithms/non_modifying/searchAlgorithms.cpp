// search algorithms
// Mikhail Nesterenko adapted from Pro C++
// 3/30/2014

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::cout; using std::endl; 
using std::vector;

int main() {
   // list of elements to be searched
   vector<int> myVector(10);
   auto begin = myVector.begin();
   auto end = myVector.end();

   // generate random values 
   // and print them out
   srand(time(nullptr));

   generate(begin, end, 
	    []{return rand()%3;});

   cout << "Generated sequence: ";
   for(auto e: myVector) cout << e << ' ' ; 
   cout << endl;

   // find the min and max elements in the vector
   auto it = min_element(begin, end);
   auto it2 = max_element(begin, end);
   cout << "min is " << *it << " and max is " << *it2 << endl;

   // find the first pair of matching consecutive elements
   it = adjacent_find(begin, end);
   if (it != end){
      cout << "Found two consecutive equal elements with value "
	   << *it << endl;
      cout << "at position: " << it - begin << endl;
   }else
      cout << "no two consequitive elements were found" << endl;

   // str.find_first_of("%*abU"); string::npos
   // str.find("abc")

   // find the first of two values
   vector<int> targets; 
   targets.push_back(0); 
   targets.push_back(1);
   
   it = find_first_of(begin, end, 
		      targets.cbegin(), targets.cend());
   if (it != end) 
      cout << "Found one of 0 or 1: " << *it 
	   << " at position: " << it - begin << endl;


   // find the first subsequence
   it = search(begin, end, targets.begin(), targets.end());
   if (it != end)
      cout << "Found subsequence {0,1}"
	   << " at position: " << it - begin << endl;
   else 
      cout << "Unable to find subsequence {0,1}" << endl;


   // find the first subsequence of two consecutive 0s
   it = search_n(begin, end, 2, 0);
   if (it != end){
      cout << "Found two consecutive zeros "
	   << "at position: " << it - begin << endl;
   } else 
      cout << "Unable to find two consecutive zeros" << endl;  
}
