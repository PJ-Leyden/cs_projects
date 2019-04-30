// using non-capturing lambda as a function pointer
// Mikhail Nesterenko
// 10/4/2016


#include <iostream>

using std::cout; using std::endl;

void func(int(*param)(int)){
   cout << param(55) << endl;
}

int main(){
   // defining lambda, assigning to function pointer
   int (*f)(int) = [](int i){return i+5;};

   func(f);
}
