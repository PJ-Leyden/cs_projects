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
   cout << "func(" << num << ", " 
	           << str << ")" << endl;
}

int main(){
   // bind second argument to a fixed value.
   string str = "abc";
   auto f1 = bind(func, _1, str);
   f1(17);


   auto f3 = bind(func, 55, _1);
   f3("hello");

   auto f4 = bind(func, 100, "howdy");
   f4();


   auto f5 = bind(func, _1, _2);
   f5(5, "foo");

   auto f2 = bind(func, _2, _1);
   f2("Test", 32);

   // nested bind
   auto f6 = bind(bind(func, 55, _1), "hi!");
   f6();

   // binding at invocation
   bind(func, 55, _1)("bye");
}
