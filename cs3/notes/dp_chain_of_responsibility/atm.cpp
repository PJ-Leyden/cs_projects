// ATM example demonstrates Chain of 
// Responsibility Pattern
// Mikhail Nesterenko
// 11/10/2017

#include <iostream>

using std::cout; using std::endl; using std::cin;

// "den" stands for "denomination"

// abstract hanlder
class CashDispenser{
public:

   CashDispenser(CashDispenser *nextDen=nullptr): 
      nextDen_(nextDen){}
   void dispense(int amount){
      const int bills = amount / getDen();
      const int remainder = amount % getDen();
      if (bills > 0 )
	 cout << bills << " " << getDen() 
	      << "-dollar bill(s) " << endl;

      if (remainder !=0){ 
	  // invoking the next handler
	  if(nextDen_ != nullptr) 
	     nextDen_->dispense(remainder);
	  else
	     cout << "no more handlers to dispense "
		  << remainder << " dollars" << endl;
      }
   }
   int getLowestDen(){
      if(nextDen_ == nullptr)
	 return getDen();
      else
	 return nextDen_->getLowestDen();
   }
   virtual int getDen()=0;
private:
   CashDispenser *nextDen_;
};


// concrete handlers
class Hundreds: public CashDispenser{
public:
   Hundreds(CashDispenser *nextDen): 
      CashDispenser(nextDen){}
   int getDen() override {return 100;};
};

class Twenties: public CashDispenser{
public:
   Twenties(CashDispenser *nextDen): 
      CashDispenser(nextDen){}
   int getDen() override {return 20;};
};

class Tens: public CashDispenser{
public:
   Tens(CashDispenser *nextDen): 
      CashDispenser(nextDen){}
   int getDen() override {return 10;};
};


int main(){
   // two ATMs with different bill denominations
   Hundreds *bigAtm = 
      new Hundreds(new Twenties(nullptr));
   Hundreds *smallAtm = 
      new Hundreds(new Twenties(new Tens(nullptr)));
   
   cout << "welcome to Firstest First Bank" << endl;
   cout << "how much money would you like to get? ";
   int amount;
   cin >> amount;

   // check which ATM is capable of dispensing amount
   if(amount % bigAtm->getLowestDen() == 0){
      cout << "Big ATM dispensing" << endl;
      bigAtm -> dispense(amount);
   } else if (amount % smallAtm->getLowestDen() == 0){
      cout << "Small ATM dispensing" << endl;
      smallAtm -> dispense(amount);
   } else
      cout << "amount needs to be divisible by "
	   << smallAtm -> getLowestDen()
	   << endl;
}
