// maps, string key
// Mikhail Nesterenko
// 3/11/2014

#include <string>
#include <iostream>
#include <map>
#include <utility>

using std::cin; using std::cout; using std::endl;
using std::string; using std::map;

int main(){

   map<string, int> employees;


   // entering entries with indexing operator
   employees["Mike"] = 123;
   employees["Charlie"] = 325;
   employees["Joe"] = 192;
   employees["Paul"] = 752;
   employees["Peter"] = 328;


   // iterating with iterator
   for(auto it=employees.cbegin(); it != employees.cend(); ++it)
      cout << it->first << " " << it->second << endl;

   cout << "Enter new employee number: "; int num; cin >> num;
   cout << "Enter new employee name: "; string name; cin >> name;

   // "safe" insert
   auto ret = employees.insert(make_pair(name,num));
   if(!ret.second)
      cout << "Employee already exists\n";

   employees[name] = num; // "unsafe" insert

   // searching map
   cout << "Enter employee name to look for: "; cin >> name;
   auto it = employees.find(name);
   if(it != employees.end())
      cout << it->first << ":" << it->second << endl;
   else
      cout << "employee not found\n";

   // removing from a map
   cout << "Enter employee name to fire: "; cin >> name;
   employees.erase(name);

   // iterating over a map
   cout << "All employees\n";
   for(const auto& e: employees)
      cout << e.first << ": " << e.second << endl;
}
