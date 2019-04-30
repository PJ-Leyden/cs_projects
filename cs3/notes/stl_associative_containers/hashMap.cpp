// unordered (hash) map example
// Mikhail Nesterenko
// 3/18/2014

#include <string>
#include <iostream>
#include <unordered_map>
#include <utility>

using std::cin; using std::cout; using std::endl;
using std::string; using std::unordered_map;

int main(){
   unordered_map<int, string> employees;

   // entering entries with indexing operator
   employees[123] = "Mike";   
   employees[345] = "Charlie";
   employees[192] = "Joe";
   employees[752] = "Paul";
   employees[328] = "Peter";
   employees[328] = "Cody";

   
   for(auto const & e: employees)
      cout << e.first << "\t" << e.second << endl;


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

   // traversing the map
   cout << "All employees\n";
   for(const auto& e: employees)
      cout << e.first << ": " << e.second << endl;

   cout << "total number of buckets: " << employees.bucket_count() << endl;
   cout << "load factor: " << employees.load_factor() << endl;
   cout << "max load factor: " << employees.max_load_factor() << endl;

   // getting the bucket for the first employee
   cout << "bucket for the first employee is: ";
   auto bucket = employees.bucket(employees.begin()->first); 
   cout << bucket << endl;
   cout << "it contains " << employees.bucket_size(bucket) << " element(s)" << endl;

   cout << "which are" << endl;
   for(auto b=employees.cbegin(bucket); 
       b!=employees.cend(bucket); ++b)
      cout << b->first << ": " << b->second << endl;
}
