// demonstrates count_if, generate, for_each using lambda as callback
// Mikhail Nesterenko
// 3/18/2014

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::cout; using std::endl; 
using std::cin;
using std::vector;
using std::generate;

int main(){
   srand(time(nullptr));
   vector <int> vect(10);

   // generate 10 random numbers
   generate(vect.begin(), vect.end(), 
	    []{return rand()%10;});
 
   cout << "Enter the number to find: ";
   int num; cin >> num;

   int cnt = count_if(vect.begin(), vect.end(), 
	     [=](int i){return i==num;});
   
   cout << "Number " << num;
   if(cnt > 0)
      cout << " occurs " 
	   << cnt << " time(s)";
   else
      cout << " is not found";
   cout << " in ";

   for_each(vect.begin(), vect.end(), 
	    [](int i){cout << i << " ";}); 
   cout << endl;
}
