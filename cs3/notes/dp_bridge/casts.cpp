// type casts 
// Mikhail Nesterenko
// 3/29/2016

#include <iostream>

using std::cout; using std::endl; using std::cin;

class Base{
public:
   virtual void example() {
      cout << "base example" << endl;
   }
};


class Derived: public Base{
public:
   void example() override {
      cout << "derived example" << endl;
   }
   void newMethod() {
      cout << "derived class method" << endl;
   }
};


// takes param by reference but does not change it
void nonConstFunc(int &i){ // 
   cout << i << " is not constant" << endl;
}


int main(){
   
   Base *bp; 
   Derived *dp;
   /* 
   // static and dynamic cast operate the same
   bp = new Derived();
   bp -> example();
 
   // dp = bp;
   
   // dp = static_cast<Derived *>(bp);

   dp = dynamic_cast<Derived *>(bp);
   dp -> example();
   */
   /*
   bp = new Base();

   // dp = static_cast<Derived *>(bp);
   
   // throws exception, returns nullptr 
   
   dp = dynamic_cast<Derived *>(bp); 
   if (dp == nullptr)
      cout << "dynamic cast failed" << endl;
   */
  
   // reinterpret_cast allows conversion 
   // without type checking

   bp = new Derived();
   
   // int i = static_cast<int>(bp); // not allowed
   
  
   int i = reinterpret_cast<int>(bp); 
   cout << i << endl;
   dp = reinterpret_cast<Derived *>(i);
   dp -> example();
  
   
   const int j=55;
   // nonConstFunc(j); // not allowed
   nonConstFunc(const_cast<int &> (j)); // ok
  
}
