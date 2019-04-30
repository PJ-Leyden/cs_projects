// list splice operation
// Mikhail Nesterenko
// 3/11/2014

#include <list>
#include <string>
#include <iostream>

using std::cout; using std::endl;
using std::list; using std::string;

int main(){

   list<string> week={"Monday", "Tuesday", 
		      "Wednesday", 
		      "Thursday", 
		      "Friday"};

   list<string> weekend={"Saturday", 
			 "Sunday"};

   // week.splice(week.end(), weekend);
   auto endOfRange = weekend.end(); 
   week.splice(week.end(), weekend, 
   	       weekend.begin(), --endOfRange);

   cout << "Week after splice: ";
   for(auto const &e: week) 
      cout << e << endl; 
   cout << endl;

   // should not be doing this
   cout << "Weekend after splice: ";
   for(auto const &e: weekend) 
      cout << e << endl; 
   cout << endl;
}
