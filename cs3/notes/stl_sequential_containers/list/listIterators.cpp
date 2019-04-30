// list iterator operation
// Mikhail Nesterenko
// 2/14/2018

#include <list>
#include <string>
#include <iostream>

using std::cout; using std::endl;
using std::list; using std::string;

int main(){

   list<string> colors={"orange", "green", 
			"yellow", "red", 
			"blue"};

   auto testit = colors.begin();

   // indexing operator is not supported
   // testit[2] = "brown";

   // operator arithmetic is not allowed
   // cout << *(testit+2) << endl;
 
   // relational operations on 
   // iterators are not allowed
   // for(auto it=colors.begin(); it < colors.end(); ++it)
   /* for(auto it=colors.begin(); it != colors.end(); ++it)
      cout << *it << ", ";
   */
   for(const auto &c : colors)
      cout << c << ", ";
   cout << endl;
   
}
