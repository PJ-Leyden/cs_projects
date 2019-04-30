// demonstrates remove in remove-erase idiom
// Mikhail Nesterenko
// 04/01/2014

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

using std::cout; using std::endl;
using std::vector;

int main() {
   vector<int> v(10);

   srand(static_cast<unsigned>(time(nullptr)));
   generate(v.begin(), v.end(), []{return rand()%10;});
   cout << "v contents: "; 
   for(auto e: v) cout << e << " "; cout << endl;
 
   
   auto toRemove=remove(v.begin(), 
			v.end(), 9);

   cout << "v contents after remove: "; 
   for(auto it=v.begin(); it != v.end(); 
       ++it) 
      cout << *it << " "; 
   cout << endl;

   v.erase(toRemove, v.end());

   cout << "v contents after erase: "; 
   for(auto it=v.begin(); it != v.end(); ++it) 
      cout << *it << " "; cout << endl;
   
   v.erase(remove_if(v.begin(), v.end(), 
	   [](int i){return i > 3;}), 
	   v.end());

   cout << "v contents after remove_if: "; 
   for(auto e: v) cout << e << " "; cout << endl;

}
