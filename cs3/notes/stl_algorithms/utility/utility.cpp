// min, max, swap, minmax
// Mikhail Nesterenko
// 3/30/2014

#include <algorithm>
#include <iostream>

using std::cout; using std::endl;
// using std::string;

using std::min; using std::max; using std::minmax; using std::swap;

template <typename T>
void testUtilities(T x, T y){
   cout << "x is " << x << ", y is " << y 
	<< ", max is " << max(x, y) 
	<< ", min is " << min(x, y) << endl;
   auto pair=minmax(x,y);
   cout << "minmax is <" << 
        pair.first <<"," << 
        pair.second
	<< "> " << endl;
   swap(x, y);
   cout << "after swaping x is " 
	<< x << ", y is " 
	<< y << endl;
}


int main() {
   testUtilities(1, 2);
   testUtilities("one", "two");

   cout << "Max out of initializer list " 
	<< max ({'a', 'b', 'z', 'x'})
        << endl;
}
