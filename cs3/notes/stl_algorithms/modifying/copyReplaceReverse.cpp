// demonstrates copy, replace, reverse
// Mikhail Nesterenko
// 04/01/2014

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

using std::cout; using std::endl;
using std::vector;

int main() {
   vector<int> v1(10), v2(10);

   srand(unsigned(time(nullptr)));
   generate(v1.begin(), v1.end(), []{return rand()%10;});
   cout << "v1 contents: "; 
   for(auto e: v1) cout << e << " "; 
   cout << endl;

   // copying contents of one vector to another
   copy(v1.begin(), v1.end(), v2.begin());
   cout << "v2 contents after simple copy(): "; 
   for(auto e: v2) cout << e << " "; cout << endl;

   // copying even numbers
   auto last=copy_if(v1.begin(), 
		     v1.end(), 
		     v2.begin(), 
		     [](int i){return i%2 ==0;});
   v2.erase(last,v2.end());


   v2.erase(copy_if(v1.begin(), v1.end(), v2.begin(), 
		    [](int i){return i%2 ==0;}),
	    v2.end());
   cout << "v2 contents after copy_if and erasing extra elements: ";
   for(auto e: v2) cout << e << " "; cout << endl;

   // replacing all elements with value 8 by value 80
   replace(v1.begin(), v1.end(), 8, 80);
   cout << "v1 contents afer replace() "; 
   for(auto e: v1) cout << e << " "; cout << endl;

   // replacing all values less than 5
   replace_if(v1.begin(), v1.end(), 
	      [](int i){return i < 5;}, 
	      5);
   cout << "v1 contents afer replace_if() "; 
   for(auto e: v1) cout << e << " "; cout << endl;

   // reversing vector 
   reverse(v1.begin(), v1.end());
   cout << "v1 contents afer reverse() "; 
   for(auto e: v1) cout << e << " "; cout << endl;
}
