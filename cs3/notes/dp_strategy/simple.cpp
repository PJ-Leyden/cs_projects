// simple Strategy Pattern example (push communication method)
// Mikhail Nesterenko
// 11/16/2014

#include <iostream>
using std::cout; using std::endl;
 

// absract strategy
class Strategy{
public:
   virtual void execute() const = 0; 
};

// concrete strategies
 
class ConcreteStrategyA: public Strategy {
public:
   void execute() const {
      cout << "executing strategy A" << endl;
   }
};
 
class ConcreteStrategyB: public Strategy {
public:
   void execute() const {
      cout << "executing strategy B" << endl;
   }
};
 
class ConcreteStrategyC: public Strategy {
public:
   void execute() const {
      cout << "executing strategy C" << endl;
   }
};
 
// context using the strategies
class Context {
public:
   Context(Strategy *strategy): strategy_(strategy) {}
   void setStrategy(Strategy *strategy) 
        {strategy_ = strategy;}
   void execute() const {strategy_->execute();}
private:
   Strategy *strategy_; 
};
 
int main() {
   // declaring strategy objects
   ConcreteStrategyA csA;
   ConcreteStrategyB csB;
   ConcreteStrategyC csC;
 
   // assigning particular strategies to contexts
   Context cA(&csA), cB(&csB), cC(&csC);
 
   // executing strategies
   cA.execute();
   cB.execute(); 
   cC.execute(); 
 
   // changing strategy at run-time
   cA.setStrategy(&csB);
   cA.execute(); 
}
