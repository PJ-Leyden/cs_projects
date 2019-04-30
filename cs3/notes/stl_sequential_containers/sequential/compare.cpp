// comparing vectors
// comparison is lexicographical
// Mikhail Nesterenko 
// 9/16/2014


#include <vector>
#include <iostream>
#include <string>

using std::vector; 
using std::cout; using std::endl;
using std::string;

int main(){
   vector <int> v1 = {1, 2, 3, 4, 5},
                v2 = {1, 2, 3, 5};
  /* 
  cout << (v1 == v2 ? 
          "v1 == v2" : "v1 != v2") << endl;
  cout << (v1 < v2 ? 
	   "v1 < v2" : "v1 => v2") << endl;
  */
   
   vector <string> 
     v4 = {"one", "two", "three"},
     v3 = {"one", "two", "three", "four"};

   cout << 
      (v3 < v4 ? 
       "v3 < v4" : "v3 => v4") << endl;

   cout << v4.length() << endl;
}
