// demonstration of std::function
// Mikhail Nesterenko
// 2/26/2016

#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; using std::endl;
using std::string; using std::vector;
using namespace std::placeholders;

// regular function
void funcReg(int n){
   cout << "funcReg, n = " << n << endl;
}


// we are going to bind this
void func(int num, string str){
   cout << "func(" << num << ", " << str << ")" << endl;
}


// functor
class MyFunctor{
public:
   MyFunctor(string x) : x_(x) {}
   // overloading function operator
   void operator() (int y) {cout << "functor, x_, y =  " << x_ << ' ' <<  y  << endl; ;}
private:
   string x_;
};




int main(){
   // a vector of functions with similar signatures
   vector<std::function<void(int)>> fv; 

   fv.push_back(funcReg);  // adding regular function
   fv.push_back(std::bind(func,_1, "abc"));   // adding bound function

   MyFunctor ftr("xyz");
   fv.push_back(ftr); // adding functor

   // adding lambda
   fv.push_back([](int x){cout << "lambda, x = " << x << endl;});

   cout << "standalone function invocation\n";
   int i=0;
   for(auto e: fv) 
      e(++i);
   cout << "\nfunction invocation in algorithm\n";

   vector<int> v = {10, 20, 30};
   for(auto e: fv)  
      std::for_each(v.begin(), v.end(), e);
  
}
