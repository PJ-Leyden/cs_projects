// reversing priority queue container adapter with a functor
// Mikhail Nesterenko
// 3/11/2014

#include <string>
#include <queue>
#include <iostream>
#include <functional>

using std::string; using std::priority_queue;  
using std::cout; using std::endl;

int main(){
   
   priority_queue<string, 
      std::vector<string>, 
      std::greater<string>> workWeekR;

   // priority_queue <string> workWeekR;

   // populating the queue, elements are stored in sorted order
   workWeekR.push("Monday");
   workWeekR.push("Tuesday"); 
   workWeekR.push("Wednesday"); 
   workWeekR.push("Thursday");
   workWeekR.push("Friday");
 
   while (!workWeekR.empty()) {
      cout << workWeekR.top() << endl;  
      workWeekR.pop();                  
   }
}
