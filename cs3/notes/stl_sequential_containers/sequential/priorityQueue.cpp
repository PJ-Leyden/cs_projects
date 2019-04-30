// container adapter: priority queue
// Mikhail Nesterenko
// 3/11/2014

#include <string>
#include <queue>
#include <iostream>

using std::string; using std::priority_queue;  
using std::cout; using std::endl;

int main(){
   /*
   priority_queue<string> workWeek;
   */

   // lowest on top
   priority_queue<string, 
           std::deque<string>, 
           std::greater<string>> workWeek;


   // populating the queue, elements are stored in sorted order
   workWeek.push("Monday");
   workWeek.push("Tuesday"); 
   workWeek.push("Wednesday"); 
   workWeek.push("Thursday");
   workWeek.push("Friday");
 
   while (!workWeek.empty()) {
      cout << workWeek.top() << endl;  
      workWeek.pop();                  
   }

   // workWeek[1]="Sunday"; // <- indexing not allowed
}
