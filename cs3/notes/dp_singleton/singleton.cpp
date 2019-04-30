// basic singleton design pattern demonstration
// Mikhail Nesterenko
// 1/26/2014

class Singleton{
public:

  // returns pointer to single instance
  static Singleton* instance(); 

  // example functions manipulating singleton object
  int getI() const {return i_;} 
  void setI(int i) {i_=i;}

private:
   // initialization is prohibited 
   Singleton(){} // private so that it cannot be invoked

   // copying prohibited
   Singleton(const Singleton&){}
   Singleton& operator=(const Singleton&){}

   // pointer to its instance
   static Singleton* onlyInstanceInt_; 

   int i_; // payload
};

// initializing pointer to its instance
Singleton* Singleton::onlyInstanceInt_ = nullptr; 

// returns pointer to instance of singleton
Singleton* Singleton::instance(){
  if(onlyInstanceInt_ == nullptr)
    onlyInstanceInt_ = new Singleton;
  return onlyInstanceInt_;
}

#include <iostream>
using std::cout; using std::endl;

// demonstration of singleton usage
int main(){

   /*
   // not allowed
   Singleton wrong;
   wrong = *(Singleton::instance());
   */

   // use directly
   Singleton::instance() -> setI(55);
   cout << Singleton::instance() -> getI() << endl;

   // or create a pointer
   Singleton *mySingleton = Singleton::instance();
   mySingleton->setI(mySingleton->getI() + 5);

   cout << mySingleton -> getI() << endl;
}
