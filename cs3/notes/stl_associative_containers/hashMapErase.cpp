// demonsrates three variants of erase() from container
// Mikhail Nesterenko (lifted from cplusplus.com)
// 10/11/2015

#include <iostream>
#include <string>
#include <unordered_map>

using std::cout; using std::endl;

int main () {
   std::unordered_map<std::string,std::string> capitals;

   // populating container:
   capitals["Canada"] = "Toronto";
   capitals["USA"] = "Washington";
   capitals["UK"] = "London";
   capitals["France"] = "Paris";
   capitals["Russia"] = "Moscow";
   capitals["China"] = "Beijing";
   capitals["Germany"] = "Berlin";
   capitals["Japan"] = "Tokyo";

   // show content:
   cout << "before erase" << endl;
   for (const auto& x: capitals)
      cout << x.first << ": " << x.second << endl;

   // erase examples:
   capitals.erase(capitals.begin());  // erasing by iterator
   capitals.erase("France");          // erasing by key

   // erasing by range
   capitals.erase(capitals.find("China"), capitals.end()); 


   // show content:
   cout << "after erase" << endl;
   for (const auto& x: capitals)
      cout << x.first << ": " << x.second << endl;
}
