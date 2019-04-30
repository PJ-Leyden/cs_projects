// nested class example
// Mikhail Nesterenko
// 11/18/2015


#include <iostream>
using std::cout; using std::endl;

class Outer{
public:
   Outer(int, int);
   int printBoth() const; 


   class Outer::InnerPublic{ // pubic nested class
   public:
      InnerPublic(int i):i_(i){}
      int geti() const;
   private:
      int i_;
   };



private:

   class InnerPrivate{  // private nested class
   public:
      InnerPrivate(int i):i_(i){}
      int geti() const; 
   private:
      int i_;
   };

   // using members of both classes as private variables
   InnerPublic pubo_; 
   InnerPrivate privo_;
};

int Outer::printBoth() const{
   // accessing methods of inner class
   // privo_.i_ =55; <-- not allowed
   return privo_.geti()+pubo_.geti(); 
}

Outer::Outer(int pubo, int privo): 
   pubo_(pubo), privo_(privo) {}


// outside definitions of members of inner classes
int Outer::InnerPublic::geti() const{
   return i_;
}
int Outer::InnerPrivate::geti() const{
   return i_;
}


int main(){

   // declaring a member of outer class
   Outer oo(5,10);
   cout << oo.printBoth() << endl;

   // declaring a member of inner class
   Outer::InnerPublic io(55);
   cout << io.geti() << endl;
}
