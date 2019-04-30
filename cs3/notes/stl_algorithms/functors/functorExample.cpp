// functor example
// Mikhail Nesterenko
// 3/30/2014

#include <iostream>
using std::cout; using std::endl;
 
class MyFunctor{
public:
   MyFunctor(int x) : x_(x) {}
   // overloading function operator
   int operator() (int y) {x_+=y; 
                           return x_;} 
private:
   int x_;
};
 
int main(){
   MyFunctor addThem(10); // creating a functor object
                          // initializing to one

   // "invoking" it like a regular function
   cout << addThem(3) << ' ';
   cout << addThem(2) << endl;

}
