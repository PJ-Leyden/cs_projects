// simple lambda expression
// Mikhail Neserenko
// 6/25/2014

#include <iostream>

using std::cout; using std::endl;

int main(){
   auto f = []{cout << "Hello, World!" << endl;};

   f();
   // alternative syntax, parentheses force execution
   []{cout << "Hi, World!" << endl;}();
}
