// demonstrates Chain of Responsibilty Pattern
// Mikhail Nesterenko
// 11/12/2016

#include <iostream>

using std::cout; using std::endl; using std::cin;

// abstract class
// sets up individual links in the 
// chain of responsibility
class Administrator {
public:
   Administrator(Administrator 
          *successor=nullptr):successor_(successor){} 
   virtual void handleRequest (int amount) {
      if (successor_ != nullptr)
	 successor_ -> handleRequest(amount);
      else
	 cout << "nobody can handle this request" 
	      << endl;
   }
private:
   Administrator *successor_;
};

// derived classes
class Teller: public Administrator{
public:
   Teller(Administrator *successor=nullptr):
                     Administrator(successor){}
   void handleRequest (int amount) override {
      if (amount < 500)
	 cout << "Teller approves request for " 
	      << amount << endl;
      else
	 Administrator::handleRequest(amount);
   }
};

class Manager: public Administrator{
public:
   Manager(Administrator *successor=nullptr):
      Administrator(successor){}
   void handleRequest (int amount) override {
      if (amount < 1000)
	 cout << "Manager approves request for " 
	      << amount << endl;
      else
	 Administrator::handleRequest(amount);
   }
};

// derived classes
class President: public Administrator{
public:
   President(Administrator *successor=nullptr):
      Administrator(successor){}
   void handleRequest (int amount) override {
      if (amount < 10000)
	 cout << "President approves request for " 
	      << amount << endl;
      else
	 Administrator::handleRequest(amount);
   }
};


int main(){
   /*
   Administrator *tp = new 
      Teller(new Manager(new President));
   */
   Administrator *tp = new 
      Teller(new President);


   int amount = 0;
   do{
      cout << "How much money would you like to withdraw? ";
      cin >> amount;
      if (amount > 0) tp->handleRequest(amount);
   } while (amount > 0);
}
