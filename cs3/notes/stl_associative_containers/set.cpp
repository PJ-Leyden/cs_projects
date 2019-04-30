// set/multiset example
// Mikhail Nesterenko
// 3/16/2014

#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>

using std::cout; using std::endl; 
using std::cin;
using std::set; using std::multiset;

int main () {
   set<char> mySet;
   multiset<char> myMset;

   srand(time(nullptr));

   for(int i=0; i < 10; ++i){
      // selecting random characters
      char newChar = 'a' + rand()%5; 
      mySet.insert(newChar); 
      myMset.insert(newChar);
   }

   // print content
   cout << "elements in mySet:" << endl;
   for(const auto& e: mySet) 
      cout << e << ' '; 
   cout << endl;

   cout << "elements in myMSet:" << endl;
   for(const auto& e: myMset) 
      cout << e << ' '; 
   cout << endl;

   myMset.erase('a');

   cout << "elements in myMSet after erasing 'a':" 
	<< endl;
   for(const auto& e: myMset) 
      cout << e << ' '; 
   cout << endl;

   // myMset.erase(myMset.begin(), myMset.end()); 
   myMset.clear();

   cout << "elements in myMSet after erasing the whole thing:" << endl;
   for(const auto& e: myMset) 
      cout << e << ' '; 
   cout << endl;

   cout << "enter a character to find: ";
   char toFind; cin >> toFind;

   auto found = mySet.find(toFind);
   if (found != mySet.end())
      cout << "found it" << endl;
   else
      cout << "not there" << endl;
   */
}
