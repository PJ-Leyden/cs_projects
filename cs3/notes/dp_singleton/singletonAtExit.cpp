// singleton with proper deallocation
// Mikhail Nesterenko
// 1/26/2014


#include <iostream>
using std::cout; using std::endl;


class Singleton{
public:

   // returns pointer to single instance
  static Singleton *instance(); 

  // example functions manipulating singleton object
  int getI() const {return i_;} 
  void setI(int i) {i_=i;}

private:

  Singleton(); // defined later 
               // to register behavior at destruction
  // copying prohibited
  Singleton(const Singleton&){}
  Singleton& operator=(const Singleton&){}

  static void cleanUp(); // correct object destruction
  static Singleton* onlyInstanceInt_; // pointer to its instance
  int i_; // payload
};

// initializing pointer to its instance
Singleton* Singleton::onlyInstanceInt_ = nullptr; 

// returns pointer to instance of singleton
Singleton* Singleton::instance(){
  if(onlyInstanceInt_ == nullptr)
     // constructor is invoked here
     onlyInstanceInt_ = new Singleton; 
  return onlyInstanceInt_;
}

#include <cstdlib>
// registering behavior at program shutdown
Singleton::Singleton(){atexit(cleanUp);} 

// deallocate instance, re-set pointer
void Singleton::cleanUp(){
   cout << "cleaning stuff up" << endl;
   delete onlyInstanceInt_; 
   onlyInstanceInt_ = nullptr;
}

// demonstration of singleton usage
int main(){

   // use directly
  Singleton::instance() -> setI(55);
  cout << Singleton::instance() -> getI() << endl;

  // or create a pointer
  Singleton *mySingleton = Singleton::instance();

  mySingleton -> setI(67);
  cout << mySingleton -> getI() << endl;
}
