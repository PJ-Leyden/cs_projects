// demoes hashmap implementation
// Mikhail Nesterenko
// 4/15/2014

#include "hashmap.h"
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
   hashmap<int, int> myHash;
   auto p1 = myHash.insert(make_pair(1, 10));
   auto p2 = myHash.insert(make_pair(2, 20));
   auto p3 = myHash.insert(make_pair(3, 30));
   auto p4 = myHash.insert(make_pair(4, 40));
   auto p5 = myHash.insert(make_pair(5, 50));
   auto p6 = myHash.insert(make_pair(6, 60));

   cout << "Key: " << p1.first->first << '\n';
   cout << "Value: " << p1.first->second << '\n';
   cout << "Bool: " << p1.second << '\n';

   cout << "Key: " << p2.first->first << '\n';
   cout << "Value: " << p2.first->second << '\n';
   cout << "Bool: " << p2.second << '\n';

   cout << "\nTry inserting a value that already exists.\nBool should be 0.\n\n";

   auto p7 = myHash.insert(make_pair(4, 40));

   cout << "Key: " << p7.first->first << '\n';
   cout << "Value: " << p7.first->second << '\n';
   cout << "Bool: " << p7.second << "\n\n\n";

   // x will have type hashmap<int, int>::value_type*
   auto x = myHash.find(4);

   if (x != nullptr) 
      cout << "Key 4 maps to: " << x->second << '\n';
   else 
      cout << "Cannot find 4 in map" << '\n';
   
   auto e = myHash.erase(4);
   if(e.second){
      cout << "Successfully removed 4.\n";
      if(e.first != nullptr){
      	 cout << "The next element is: " << e.first->second << '\n';
      }else{
      	 cout << "There is no next element.\n";
      }
   }else{
   	  cout << "Failed to remove 4. Not in the map.\n";
   }
   
   myHash[4] = 35;
   myHash[4] = 60;

   auto x3 = myHash.find(4);
   if (x3 != nullptr)
      cout << "4 maps to " << x3->second << endl;
   else 
      cout << "cannot find 4 in map" << endl;

   myHash.rehash(200);
   std::cout << "rehashed\n";
/*

   hashmap<int, string> employees;

   // entering entries with indexing operator
   employees[123] = "Mike";
   employees[345] = "Charlie";
   employees[192] = "Joe";
   employees[752] = "Paul";
   employees[328] = "Peter";

   cout << "Enter new employee number: "; int num; cin >> num;
   cout << "Enter new employee name: "; string name; cin >> name;

   employees[num] = name; // "unsafe" insert

   // searching map
   cout << "Enter employee number to look for: "; cin >> num;
   auto it = employees.find(num);
   if(it != nullptr)
      cout << it->first << ":" << it->second << endl;
   else
      cout << "employee not found" << endl;

   // removing from a map
   cout << "Enter employee number to fire: "; cin >> num;
   employees.erase(num);
   // check if not there
   auto removed = employees.find(num);
   if (removed == nullptr)
      cout << "Employee removed successfully" << endl;
*/

}
