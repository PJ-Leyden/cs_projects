// demo bind()
// Mikhail Nesterenko, adapted form Pro C++
// 3/29/2014

#include <iostream>
#include <string>
#include <functional>

using std::cout; using std::endl; using std::string;
using namespace std::placeholders;

// function to use to demo binding
void func(int num, const string& str){
   cout << "func(" << num << ", " << str << ")" << endl;
}

int main(){
   // bind second argument to a fixed value.
   string str = "abc";
   // auto f1 = bind(func, _1, str);
   // void (*f1)(int) = bind(func, _1, str);

   // f1(16);

   // void (*f1)(int, const string &) = bind(func, _1, _2);
  
}
