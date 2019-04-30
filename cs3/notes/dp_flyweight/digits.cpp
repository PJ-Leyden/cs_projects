// combining composite and flyweight
// Mikhail Nesterenko
// 4/26/2016

// the expressions are
// expression ::= number | expression + expression 
//                       | expression - expression

#include <iostream>
#include <string>
#include <map>

using std::cout; using std::endl; using std::cin;
using std::string; 

// abstract flyweight
class Digit{
public:
   virtual int value() =0;
   virtual string image() = 0;
};

// several concrete flyweights
class Zero: public Digit {
public:
   int value(){return 0;}
   string image(){return "zero";}
};

class One: public Digit {
public:
   int value(){return 1;}
   string image(){return "one";}
};

class Two: public Digit {
public:
   int value(){return 2;}
   string image(){return "two";}
};



// flyweight factory
class DigitFactory{
public:
   static Digit *makeDigit(int d){

      if(digits_.find(d) == digits_.end())
	 switch(d){
	 case 0:
	    digits_[d] = new Zero; break;
	 case 1:
	    digits_[d] = new One; break;
	 default: // all other digits are two
	    digits_[d] = new Two; break;
	 }
      return digits_[d];
   }
private:
   static std::map<int, Digit*> digits_;
};

std::map<int, Digit*> DigitFactory::digits_;


// component
class Expression{
public:
   virtual int evaluate()=0; 
   virtual string print()=0; 
   virtual ~Expression(){}
};


// leaf using flyweight object
class Number: public Expression {
public:
   Number(int value) { d_ = DigitFactory::makeDigit(value);}
   int evaluate(){return d_->value();}
   string print(){return d_->image();}
private: 
   Digit *d_;
};

// several composites
class Add: public Expression {
public:
   Add(Expression *left, Expression *right): 
      left_(left), right_(right){}
   int evaluate() {
      return left_->evaluate() + right_->evaluate();
   }
   string print() {
      return '(' + left_->print() + '+' 
	         + right_->print() + ')';
   }
private:
   Expression *left_;
   Expression *right_;
};

class Subtract: public Expression {
public:
   Subtract(Expression *left, Expression *right): 
      left_(left), right_(right){}
   int evaluate() {
      return left_->evaluate() - right_->evaluate();
   }
   string print(){
      return '(' + left_->print() + '-' + right_->print() + ')';
   }
private:
   Expression *left_;
   Expression *right_;
};


int main(){
   Expression *example1 = 
      new Add(new Number(2), new Number(1));
   cout << example1->print() 
	<< " = " << example1->evaluate() << endl;  

   Expression *example2 = 
      new Subtract(example1, new Number(2));

   cout << example2->print() 
	<< " = " << example2->evaluate() << endl;  
}
