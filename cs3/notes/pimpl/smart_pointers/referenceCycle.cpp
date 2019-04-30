// demonstrates and breaks reference cylce with weak_ptr
// Mikhail Nesterenko
// 11/24/2015

#include <memory> 
#include <iostream>


class B; // forward declaration 

class A { 
public: 
   std::shared_ptr<B> b_; 
   ~A() {std::cout << "destructor of A" << std::endl; } 
};  

class B { 
public: 
   // std::shared_ptr<A> a_; 
   std::weak_ptr<A> a_;
   ~B() {std::cout << "destructor of B" << std::endl; } 
};     


int main(){
   auto a = std::make_shared<A>();
   auto b = std::make_shared<B>();

   a->b_ = b;
   b->a_ = a;
}
