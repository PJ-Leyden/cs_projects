// demonstrates enum type
// Mikhail Nesterenko
// 2/18/2014


#include <iostream>
#include <cstdlib>

using std::cout; using std::endl;

enum Day {Monday, Tuesday, 
	  Wednesday, Thrusday, Friday, Saturday, Sunday};
const int NUMWEEKDAYS=7;

int main(){
   srand(time(nullptr));

   Day today = Day(rand() % NUMWEEKDAYS);
   if(today == Saturday || today == Sunday)
      cout << "We got a weekend!\n";
}
