// deque example
// Mikhail Nesterenko
// 6/24/2015

#include <iostream>
#include <deque>

using std::deque; 
using std::cout; using std::endl;

int main(){
   deque<int> dOne, dTwo;

   // adding to front and back of container
   for(int i=0; i<10; ++i) {
      dOne.push_front(i);
      dTwo.push_back(i);
   }

   // removing from front, adding to front
   for(int i=0; i<5; ++i) {
      dOne.push_front(dTwo.front());
      dTwo.pop_front();
   }

   // printing out containers
   cout << "dOne: ";
   for(int i=0; i < dOne.size(); ++i) 
      cout << dOne[i] << " "; 
   cout << endl;

   cout << "dTwo: ";
   for(auto it = dTwo.cbegin(); it != dTwo.cend(); ++it) 
      cout << *it << " "; 
   cout << endl;

   
   // iterator arithmetic

   auto it=dOne.begin();

   it += 5;

   cout << *it++ << ' '
	<< *++it << ' '
	<< *(it + 5) << ' '
        << dOne[it - dOne.begin()] << endl;
  
}
