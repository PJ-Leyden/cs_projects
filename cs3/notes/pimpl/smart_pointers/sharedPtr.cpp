// shared_ptr basic usage example
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
   ~Myclass()     
    { cout << "destroying " << i_ << endl; }
private:
   int i_;
};

// note pass by value
void myfunc(std::shared_ptr<int> i) { 
   ++*i;
}

int main() {

   /*  
   // manipulating shared integers
   auto sp = std::make_shared<int>(10);
   auto sp2(sp);
   cout << "number of references: " << sp.use_count() << endl;
   myfunc(sp2);
   cout << *sp << endl;
   */

   // manipulating shared objects
   auto sm = std::make_shared<Myclass>(10);
   cout << "there are " << sm.use_count() << " shared pointers\n";

   auto sm2 = sm;
   cout << "there are " << sm.use_count() << " shared pointers\n";


   // accessing object through two shared pointers
   sm->myfunc(); 
   sm2->myfunc();

   // shared pointers may be compared
   if(sm == sm2) {
      sm.reset(); // reassigning the first pointer
      sm2->myfunc(); // object still exists
      sm2 = nullptr; // last reference, destroys object
      cout << "object is not here anymore" << endl;
   }
 
}
