// demonstates the operation of a static variable in a loop
// Mikhail Nesterenko
// 7/17/2015

#include <iostream>

using std::cout; using std::endl;


int main(){
   for(int i=0; i < 10; ++i){
      static int j=0;
      int k = 0;
      cout << "j=" 
	   << ++j 
	   << " k=" << ++k << endl;
   }
}
