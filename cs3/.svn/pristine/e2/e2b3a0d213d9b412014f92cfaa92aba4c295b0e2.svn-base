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
   myHash.insert(pair<int,int>(4, 40));
   myHash.insert(make_pair(6, 60));

   // x will have type hashmap<int, int>::value_type*
   auto x = myHash.find(4);
   if (x != nullptr) 
      cout << "4 maps to " << x->second << endl;
   else 
      cout << "cannot find 4 in map" << endl;
   

   myHash.erase(4);

   auto x2 = myHash.find(4);
   if (x2 != nullptr)
      cout << "4 maps to " << x2->second << endl;
   else 
      cout << "cannot find 4 in map" << endl;
   
   myHash[4] = 35;
   myHash[4] = 60;

   auto x3 = myHash.find(4);
   if (x3 != nullptr)
      cout << "4 maps to " << x3->second << endl;
   else 
      cout << "cannot find 4 in map" << endl;

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

}
