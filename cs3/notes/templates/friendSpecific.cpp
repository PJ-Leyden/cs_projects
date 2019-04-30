// friend to a templated class with specialzed template
// Mikhail Nesterenko
// 2/2/2016
#include <iostream>

using std::cout; using std::endl;


// forward class declaration
template<typename T>
class Myclass;

// forward function declaration
template<typename T>
bool equal(const Myclass<T>&, const Myclass<T>&);


template <typename T>
class Myclass{ 
public:
   Myclass(int, T, T);

   // this is a friend to only a single instance
   // note the engle brakets: tells compiler it is a template
   friend bool equal<T>(const Myclass&, const Myclass&);
private: 
   int a_; 
   T b_; 
   T *c_; 
};  


// constructor definition
template <typename T>
Myclass<T>::Myclass(int a, T b, T c): a_(a), b_(b){
   c_=new T(c);
}


// friend function definition
template <typename T> 
bool equal(const Myclass<T> &x, const Myclass<T> &y) {
   return x.a_==y.a_ && x.b_==y.b_ && *(x.c_)==*(y.c_);
} 



int main(){

   Myclass<char> ob1(1, 'a', 'b'), 
                 ob2(1, 'a', 'b'), 
                 ob3(1, 'a', 'c');

   if(equal(ob1, ob2)) cout << "ob1 is equal to ob2" << endl;
   if(!equal(ob1, ob3)) cout << "ob1 is not equal to ob3" << endl;
   
}
