// tests hashmap container implementation
// Mikhail Nesterenko, lifted from Pro C++
// 4/20/2014

#include "hashmap.h"
#include <iostream>
#include <map>
// using namespace std;

using std::cout; using std::cin; using std::endl;
using std::make_pair;
using std::map;

int main(){
   hashmap<string, int> myHash;
   myHash.insert(make_pair("KeyOne", 100));
   myHash.insert(make_pair("KeyTwo", 200));
   myHash.insert(make_pair("KeyThree", 300));
   myHash.insert(make_pair("KeyFour", 400));

   for (auto it = myHash.cbegin(); it != myHash.cend(); ++it) {
      // Use both -> and * to test the operations
      cout << it->first << " maps to " << (*it).second << endl;
   }

   cout << "----" << endl;

   // Print elements using C++11 range-based for loop
   for (auto& p : myHash)
      cout << p.first << " maps to " << p.second << endl;

   cout << "----" << endl;

   // Create a map with all the elements in the hashmap
   map<string, int> myMap(myHash.begin(), myHash.end());
   for (auto it = myMap.begin(); it != myMap.end(); ++it) {
      cout << it->first << " maps to " << (*it).second << endl;
   }

   hashmap<string, int> myHash2;
   myHash.swap(myHash2);
   hashmap<string, int>myHash3(myHash2);

   cout << "Hash size: " << myHash2.size() << endl;
   cout << "Hash max size: " << myHash2.max_size() << endl;

   hashmap<int, string> employees;
   // entering entries with indexing operator
   employees[123] = "Mike";
   employees[345] = "Charlie";
   employees[192] = "Joe";
   employees[752] = "Paul";
   employees[328] = "Peter";

   cout << "Enter new employee number: "; int num; cin >> num;
   cout << "Enter new employee name: "; string name; cin >> name;

   // "safe" insert
   auto ret = employees.insert(make_pair(num,name));
   if(!ret.second)
      cout << "Employee already exists\n";

   employees[num] = name; // "unsafe" insert

   // searching map
   cout << "Enter employee number to look for: "; cin >> num;
   auto it = employees.find(num);
   if(it != employees.end())
      cout << it->first << ":" << it->second << endl;
   else
      cout << "employee not found\n";

   // removing from a map
   cout << "Enter employee number to fire: "; cin >> num;
   employees.erase(num);

   // iterating over a map
   cout << "All employees\n";
   for(auto& e: employees)
      cout << e.first << ": " << e.second << endl;
}
