// unique_ptr basic usage example
// Mikhail Nesterenko
// 11/24/2015


#include <iostream>
#include <memory>
 
using std::cout; using std::endl;

class Myclass{
public:
   Myclass(int i):i_(i)
     { cout << "constructing " <<  i_ <<endl;  }
   void myfunc() const 
     { cout << "accessing " << i_ << endl;  }
   ~Myclass(){ cout << "destroying " << i_ << endl;; }
private:
   int i_;
};
 
 
int main() {

   // p1 owns new object
   std::unique_ptr<Myclass> p1(new Myclass(1));  
   // auto p1 = make_unique<Myclass>();

   p1->myfunc(); // accessing first object

   // unique_ptr may be used in boolean expressions
   if (p1){ 
      // now p2 owns first object
      std::unique_ptr<Myclass> p2(std::move(p1));

      if(!p1) cout << "p1 is not initialized" << endl;
          
      // p1 = p2; // copying prohibited
      
      p1 = std::move(p2);  // ownership returns to p1
      
      p1 = std::unique_ptr<Myclass>(new Myclass(5)); // assignment from raw pointer prohibited
      /*
      if(!p2) cout << "p2 is not initialized" << endl;

      p2.reset(new Myclass(2)); // reassigning p2
      p2->myfunc();
      */   
   } // second object goes out of scope
  
   /*
   p1->myfunc(); // first object still
   p1 = nullptr; // this destroys first object
   */
}
