// demonstrates move semantics
// Mikhail Nesterenko
// 9/5/2014

#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector;

class MovableClass{
public:
   MovableClass(){
      cout << "default constructor" 
	   << endl;}
   MovableClass(const MovableClass& src)
               {cout 
		<< "copy constructor" 
		<< endl;}
   MovableClass(MovableClass&& src)
               {cout << 
		     "move constructor" 
		     << endl;}

   MovableClass& operator= (const MovableClass &rhs){
      cout << "copy assignment" 
	   << endl;
      return *this;
   }

   MovableClass& operator= (MovableClass &&rhs){
      cout << "move assignment" << endl;
      return *this;
   }
};


void myFunc(MovableClass funcObj){
}

int main(){

   vector<MovableClass> v;
   MovableClass mo;
   /*
   v.push_back(mo); 
   v.push_back(std::move(mo)); 
   */

   /*
                    // constructor as vector v enlarges
   vector<MovableClass> v2;
   // std::move(v.begin(), v.end(), inserter(v2, v2.end()));
   */

   // invokes move constructor explictly
   MovableClass mo2 = std::move(mo); 
  
   mo2 = std::move(mo);
   /*
   MovableClass mo3 = myFunc(); 
   */

   // invokes move assignment on temporary object
   // mo3 = myFunc();

}
