// modifying key order in a map
// Mikhail Nesterenko
// 10/10/2016

#include <iostream>
#include <string>
#include <map>
#include <utility>

using std::cout; using std::endl;
using std::string; using std::map;
 
int main() {
   map<string, int> months;
   map<string, int, std::greater<string>> gmonths;

   months["january"] = 31;    gmonths["january"] = 31;
   months["february"] = 28;   gmonths["february"] = 28;  
   months["march"] = 31;      gmonths["march"] = 31;
   months["april"] = 30;      gmonths["april"] = 30;
   months["may"] = 31;        gmonths["may"] = 31;
   months["june"] = 30;       gmonths["june"] = 30;
   months["july"] = 31;       gmonths["july"] = 31;
   months["august"] = 31;     gmonths["august"] = 31;
   months["september"] = 30;  gmonths["september"] = 30;
   months["october"] = 31;    gmonths["october"] = 31;
   months["november"] = 30;   gmonths["november"] = 30;
   months["december"] = 31;   gmonths["december"] = 31;

   cout << "default map order:" << endl;
   for(auto it = months.cbegin();  it != months.cend(); ++it)
      cout << "\t" << it->first << " has " 
	   << it->second << " days" << endl;
   cout << endl;
   
   cout << "modified map order:" << endl;
   for(auto it = gmonths.cbegin();  it != gmonths.cend(); ++it)
      cout << "\t" << it->first << " has "
           << it->second << " days" << endl;




}
