// comparison algorithms
// Mikhail Nesterenko, adapted from Pro C++
// 3/30/2014

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <cstdio>

using std::cout; using std::cin; using std::endl;
using std::vector; using std::list;

// Function template to populate a container or characters
// The container must support push_back().
template<typename Cont>
void populateContainer(Cont& cont){
   cout << "enter characters, '0' to quit: ";
   while (true) {
      char item;
      cin >> item;
      if (item == '0') break;
      cont.push_back(item);
   }
}

int main(){
   vector<char> myVector;
   list<char> myList;

   cout << "Populate the vector "; 
   populateContainer(myVector);

   cout << "Populate the list "; 
   populateContainer(myList);

   if (myList.size() < myVector.size()) {
      cout << "The list is not long enough." << endl;
      exit(1);
   }

   // compare the two containers
   if (equal(myVector.begin(), 
	     myVector.end(), 
	     myList.begin())) 
      cout << "The two containers have equal elements" 
	   << endl;
   else{
      // If the containers were not equal, 
      // find out why not
      auto miss =mismatch(myVector.begin(), 
			   myVector.end(), 
			   myList.begin());
      cout << "this is the equal prefix" 
	   << endl;
      for_each(myVector.begin(), 
	       miss.first, 
	       [](char c){cout << c;});
      cout << endl;
   }

   // Now order them
   // accept < acceptance < access
   if (lexicographical_compare(
		 myVector.begin(), 
		 myVector.end(), 
		 myList.begin(),   
		 myList.end()))
      cout << "the vector comes first" << endl;
   else 
      cout << "the list comes frist" << endl;
}
