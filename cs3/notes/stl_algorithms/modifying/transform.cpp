// demonstrates two versions of transform
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

   srand(static_cast<unsigned>
	 (time(nullptr)));

   generate(v1.begin(), v1.end(), 
	    []{return rand()%10;});


   cout << "v1 contents: "; 
   for(auto e: v1) cout << e << " "; 
   cout << endl;

   // transform used on non-overlapping ranges
   transform(v1.begin(), 
	     v1.end(), 
	     v2.begin(), 
	     [](int i){return i+10;});

   cout << "v2 contents after transform(): "; 
   for(auto e: v2) cout << e << " "; 
   cout << endl;

   // transform used on overlapping (the same) range
   transform(v1.begin(), 
	     v1.end(), 
	     v1.begin(), 
	     std::negate<int>());
   
   cout << "v1 contents after transform(): "; 
   for(auto e: v1) cout << e << " "; cout << endl;

   
   transform(v1.begin(), 
	     v1.end(), 
	     v2.begin(), 
	     v1.begin(),
	     [](int i, int j){return i+j;});

   cout << "v1 contents after two-range transform(): "; 
   for(auto e: v1) 
      cout << e << " "; 
   cout << endl;
}
