// utility pair class
// Mikhail Nesterenko
// 3/16/2014

#include <utility>
#include <string>
#include <iostream>

using std::cout; using std::endl;
using std::pair; using std::string;

int main(){
   pair <int, string> pairOne(1, "one");
   // pair <int, string> pairTwo(2, "two");
   auto pairTwo = 
      pair<int, string>(2, "two");

   if(pairOne < pairTwo) // pair comparison
      cout <<  "<" << pairOne.first 
           << ", " << pairOne.second 
	   << "> is smaller" << endl;
   // deduces elements of a pair, C++11
   // creates a new pair 
   auto pairThree = std::make_pair(3.1, 'a'); 



   cout << "newly made pair: <" << pairThree.first 
        << ", " << pairThree.second << ">" << endl;

   auto ptr = &pairThree;
   cout << "accessing pairThree through pointer: " 
	<< ptr->first << " "
	<< (*ptr).second << endl;

}
