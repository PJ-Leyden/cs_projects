// recursive lambda function using std::function
// Mikhail Nesterenko
// 10/4/2016

#include <functional>
#include <iostream>

using std::cout; using std::endl;

int main(){

   std::function<int(int)> factorial;

   factorial = [&factorial] (int a) {
      if( a>1 )
	 return a*factorial(a-1);
      else
	 return 1;
   };


   cout << factorial(5) << " " << factorial(10) << endl;
}
