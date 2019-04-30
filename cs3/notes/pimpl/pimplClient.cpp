// demonstrates using handle as ordinary class
// Mikhail Nesterenko
// 11/24/2014


#include <iostream>
#include "pimpl.h"

using std::cout; using std::endl;

// sample client code
int main(){
   Handle a, b;
   a.setData(22);
   b = a;
   a.setData(55);
   cout << a.getData() << ' ' <<  b.getData() << endl;
}
