// singleton with delete syntax
// Mikhail Nesterenko
// 3/14/2016

class Singleton{
public:

  // returns pointer to single instance
  static Singleton* instance(); 

  // example functions manipulating singleton object
  int getI() const {return i_;} 
  void setI(int i) {i_=i;}

   // copying prohibited
   Singleton(const Singleton&) = delete;
   Singleton& operator=(const Singleton&) = delete;


private:

   Singleton(){}  // initialization is hidden

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
   Singleton wrong2;
   wrong2 = wrong;
   */

   // use directly
   Singleton::instance() -> setI(55);
   cout << Singleton::instance() -> getI() << endl;

   // or create a pointer
   Singleton *mySingleton = Singleton::instance();
   mySingleton->setI(mySingleton->getI() + 5);

   cout << mySingleton -> getI() << endl;
}
