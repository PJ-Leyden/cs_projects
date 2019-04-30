// demonstrates enum class
// Mikhail Nesterenko
// 2/18/2014


#include <iostream>
#include <cstdlib>

using std::cout; using std::endl;

enum class Week {Monday, Tuesday, Wednesday, Thrusday,
      Friday, Saturday, Sunday, number}; 
     // number is to keep track of cardianlity


int main(){
   srand(time(nullptr));

   // rand() % Week::number // <- can't just use this because they are typed
   // need to explictly cast to integer

   Week today = 
         Week(rand() % static_cast<int>(Week::number));

   if(today == Week::Saturday || today == Week::Sunday)
      cout << "It's weekend!\n";
   else
      cout << "It's a workday.\n";

}
