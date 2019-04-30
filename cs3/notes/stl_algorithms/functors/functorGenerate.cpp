// functor usage with algorithms
// Mikhail Nesterenko
// 3/30/2014

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout; using std::endl;
using std::vector;

class MyFunctor{
public:
   MyFunctor(int x) : x_(x) {}
   // overloading function operator
   int operator() () {return x_;} 
private:
   int x_;
};
 
int main(){
   // creating a functor object
   MyFunctor addIt(5); 
                        // initializing to 5
   vector<int> v(10);

   generate(v.begin(), v.end(), addIt);

   //   for(auto e: v) cout << e << " "; cout << endl;

   for_each(v.begin(), v.end(), 
	    [](int e){cout << e << " ";});
   cout << endl;
}
