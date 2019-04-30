// demonstrates map operations
// Mikhail Nesterenko
// 10/7/2014

#include <iostream>
#include <string>
#include <map>
#include <utility>

using std::cout; using std::endl;
using std::string; using std::map;
 

void printDays(map<string, int>::iterator month){
   cout << month->first << " has " 
	<< month->second << " days" << endl;
}


int main() {
   map<string, int> months = {{"january",15},
			      {"march", 44}};

   auto location = months.find("january");
   if(location != months.end())
      location->second = 31;
   else
      months.insert(std::make_pair("january",55));

   printDays(months.find("january"));
 

   months.insert(std::make_pair("february", 28));

   // months["february"] = 28;

   months["march"] = 31;
   months["april"] = 30;
   months["may"] = 31;
   months["june"] = 30;
   months["july"] = 31;
   months["august"] = 31;
   months["september"] = 30;
   months["october"] = 31;
   months["november"] = 30;
   months["december"] = 31;

   printDays(months.find("january"));
   printDays(months.find("february"));   
   printDays(months.find("december"));
}
