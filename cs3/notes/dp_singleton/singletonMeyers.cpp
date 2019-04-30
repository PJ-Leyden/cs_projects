// Meyers Singleton
// Mikhail Nesterenko
// 7/8/2014

#include <vector>
#include <iostream>

using std::cout; using std::endl;
using std::vector;

class SingletonVect{
public:
   static SingletonVect& instance(){
      static SingletonVect s;
      return s;
   }

   //example functions manipulating singleton object
   void addChar(char c) {chars_.push_back(c);} 
   void print() {
      for(auto c: chars_) 
	 cout << c << ' '; 
      cout << endl;
   }

   ~SingletonVect(){
      cout << "This is a destructor" << endl;
   }


private:
   // copying and creation prohibited 
   SingletonVect(){}
   SingletonVect(const SingletonVect&){}
   SingletonVect& operator=(const SingletonVect&){}
   vector<char> chars_; // payload
   
};


// demonstration of singleton usage
int main(){

   /*
   SingletonVect wrongV;
   SingletonVect wrongV2;
   wrongV.addChar('x');
   wrongV2=wrongV;
   wrongV2.addChar('y');
   wrongV.print();
   wrongV2.print();
   */

   SingletonVect::instance().addChar('a');
   SingletonVect::instance().addChar('b');
   SingletonVect::instance().addChar('c');
   SingletonVect::instance().print();
   
   SingletonVect &v=SingletonVect::instance();
   v.addChar('d');
   v.print();
   
}
