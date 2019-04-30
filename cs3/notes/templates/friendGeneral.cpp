// friend to a templated class with general template
// Mikhail Nesterenko
// 2/2/2016

#include <iostream>

using std::cout; using std::endl;

template <typename T>
class Myclass{ 
public:
   Myclass(int, T, T);
   // defines friend to all instantiated classes
   template <typename U> 
   friend bool equal(const Myclass<U>&, const Myclass<U>&);
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

// friend function defintion
template <typename U> 
bool equal(const Myclass<U> &x, const Myclass<U> &y) {
   return x.a_==y.a_ && x.b_==y.b_ && *(x.c_)==*(y.c_);
} 

int main(){

   Myclass<char> ob1(1, 'a', 'b'), 
                 ob2(1, 'a', 'b'), 
                 ob3(1, 'a', 'c');
   
   if(equal(ob1, ob2)) cout << "ob1 is equal to ob2" << endl;
   if(!equal(ob1, ob3)) cout << "ob1 is not equal to ob3" << endl;
   
}
