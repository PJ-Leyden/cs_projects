// demonstrates Visitor Design Pattern and double dispatch
// Mikhail Nesterenko
// 11/29/2014

#include <iostream> 
#include <string> 
#include <vector> 

using std::cout; using std::endl;
using std::string;
using std::vector;

// abstract element
class CarPart{
public:
   virtual void accept(class CarPartVisitor*) = 0;
};




// abstract visitor
class CarPartVisitor{
public:
   virtual void visit(class Engine*) =0;
   virtual void visit(class Transmission*) =0;
   virtual void visit(class Wheel*) =0;
};



// concrete elements

class Engine: public CarPart {
public:
   void accept(CarPartVisitor *v) {v->visit(this);}
};

class Transmission: public CarPart {
   void accept(CarPartVisitor *v) {v->visit(this);}
};

class Wheel : public CarPart {
public:
   Wheel(const string &place) : place_(place) {}
   const string &getPlace() const {return place_;}
   void accept(CarPartVisitor *v) {v->visit(this);}
private:
   string place_;
};

// simple concrete visitor
class Inspector : public CarPartVisitor {
public:
   void visit(Engine *e) {
      cout << "Inspector checks engine" << endl; 
   }
   void visit(Transmission *t) { 
      cout << "Inspector checks transmission" << endl; 
   }
   void visit(Wheel *w) { 
      cout << "Inspector checks " 
	   << w->getPlace() << " wheel" 
	   << endl; 
   }
};

// stateful concrete visitor
class Operator : public CarPartVisitor {
public:
   Operator(): ops_(0) {}
   void visit(Engine *e) { 
      cout << "Operator starts engine; so far ops: " 
	   << ++ops_ << endl;
   }
   void visit(Transmission *t) {
      cout << "Operator shifts transmission; so far ops: " 
	   << ++ops_ << endl;
   }
   void visit(Wheel *w){  
      cout << "Operator turns " 
	   << w->getPlace() 
	   << " wheel; " 
	   << "so far ops: " << ++ops_ << endl;}
private:
   int ops_; // number of operations performed
};


int main(){
   vector <CarPart *> parts = {new Engine, 
			       new Transmission,
			       new Wheel("front left"),
			       new Wheel("rear right")};

   vector <CarPartVisitor *> visitors = {new Inspector,
				         new Operator};
   for(auto e: parts){
      for(auto v: visitors)
	 e->accept(v); // method is dispatched on 
                       // the basis of types of 
                       // both "e" and "v"
      cout << endl;
   }
}
