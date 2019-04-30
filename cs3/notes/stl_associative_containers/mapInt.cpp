// maps, integer key
// Mikhail Nesterenko
// 3/11/2014

#include <string>
#include <iostream>
#include <map>
#include <utility>

using std::cin; using std::cout; using std::endl;
using std::string; using std::map;

int main(){
   map<int, string> employees;

   // entering entries with indexing operator
   employees[123] = "Mike";
   employees[345] = "Charlie";
   employees[192] = "Joe";
   employees[752] = "Paul";
   employees[328] = "Peter";


   for(auto it=employees.cbegin(); 
       it != employees.cend(); ++it)
            cout << it->first << ": " 
		 << it->second << endl;

   cout << "Enter new employee number: "; 
   int num; cin >> num;
   cout << "Enter new employee name: "; 
   string name; cin >> name;

   //
   // inserting
   //

   // "safe" insert
   auto ret = employees.insert(make_pair(num,name));
   // alternative
   // auto ret = 
   //  employees.insert(
   //	   std::pair<int,string>(num,name));
   // alternative with const values
   // auto ret = employees.insert(
   //                   {999, "Joseph"});
  
   /*
   if(!ret.second){
      cout << "Employee already exists, ";
      cout << "The name is: " << 
	       ret.first->second << endl;
   }
   */
   /*   
   // inserting with a hint
   auto result = 
   employees.insert(
   employees.begin(), make_pair(num,name));

   cout << "Result of insert: " << result -> first << ", " << 
                                result -> second << endl;

   */
   
   employees[num] = name; // "unsafe" insert
   
   // inserting with a range
   map<int, string> managers;
   managers.insert(employees.begin(), 
		   employees.end());

   cout << "All managers\n";
   for(const auto& e: managers)
      cout << e.first << ": " 
	   << e.second << endl;
   
   //
   // searching
   //
   cout << "Enter employee number to look for: "; 
   cin >> num;

   auto it = employees.find(num);

   if(it != employees.end()){
      cout << it->first << ":" << it->second << endl;
   }     
   else
      cout << "employee not found\n";

 
   //
   // erasing
   //
   cout << "Enter employee number to fire: "; 
   cin >> num;
   employees.erase(num);

   /*
   // erasing with a range
   employees.erase(employees.begin(), 
		   employees.find(num));
   */
   
   cout << "All employees\n";
   // traversing with range-based for  
   for(const auto& e: employees)
      cout << e.first << ": " 
	   << e.second << endl;

}
