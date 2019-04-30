// elementary calculator using Composite 
// Mikhail Nesterenko
// 10/28/2015

// the expressions are
// expression ::= number | 
//                expression + expression | 
//                expression - expression |
//                expression * expression | 
//                expression / expression

// the expressions are left associative and 
// there is no precedence between
// addition/subraction and multiplication/division



#include <iostream>
#include <string>

using std::cout; using std::endl; using std::cin;
using std::string; 

// component
class Expression{
public:
   virtual int evaluate()=0; 
   virtual string print()=0; 
   virtual ~Expression(){}
};


// leaf
class Number: public Expression {
public:
   Number(int value): value_(value){}
   int evaluate() override {return value_;}
   string print() override 
          {return std::to_string(value_);}
private: 
   int value_;
};

// several composites
class Add: public Expression {
public:
   Add(Expression *left, Expression *right): 
      left_(left), right_(right){}
   int evaluate() override {
      return left_->evaluate() + 
	     right_->evaluate();
   }
   string print() override {
      return '(' + left_->print() + '+' + 
                   right_->print() + ')';
   }
private:
   Expression *left_;
   Expression *right_;
};

class Subtract: public Expression {
public:
   Subtract(Expression *left, Expression *right): 
      left_(left), right_(right){}
   int evaluate() override {
      return left_->evaluate() - right_->evaluate();
   }
   string print() override {
      return '(' + left_->print() + '-' + right_->print() + ')';
   }
private:
   Expression *left_;
   Expression *right_;
};


class Multiply: public Expression {
public:
   Multiply(Expression *left, Expression *right): 
      left_(left), right_(right){}
   int evaluate() override {
      return left_->evaluate() * right_->evaluate();
   }
   string print() override {
      return left_->print() + '*' + right_->print();
   }
private:
   Expression *left_;
   Expression *right_;
};


class Divide: public Expression {
public:
   Divide(Expression *left, Expression *right): 
      left_(left), right_(right){}
   int evaluate() override {
      return left_->evaluate() / right_->evaluate();
   }
   string print() override {
      return left_->print() + '/' + right_->print();
   }
private:
   Expression *left_;
   Expression *right_;
};



int main(){

   Expression *const55 = new Number(55);

   cout << const55->print() 
	<< " = " << const55->evaluate() << endl;

   
   Expression *exp1 = new Add(const55, new Number(13));
   cout << exp1->print() << " = " 
	<< exp1->evaluate() << endl;


   Expression *const42 = new Number(42); 
  
   Expression *exp2 = 
      new Subtract(exp1, new Add(const42, new Number(9)));
   cout << exp2->print() << " = " << exp2->evaluate() << endl;

   Expression *exp3 = new Divide(exp1, exp2);
   cout << exp3->print() << " = " << exp3->evaluate() << endl;

   cout << "Enter first factor: "; int factor1; cin >> factor1;
   cout << "Enter second factor: "; int factor2; cin >> factor2;
   Expression *product = new Multiply(new Number(factor1), new Number(factor2));
   cout <<  product->print() << " = " << product->evaluate() << endl;
}
