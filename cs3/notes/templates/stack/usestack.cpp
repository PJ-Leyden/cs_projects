// templated stack instantiation
// Mikhail Nesterenko
// 2/25/2014

#include <iostream>
#include "stack.h"

using std::cout; using std::cin; using std::endl;

#include <string>
using std::string;

// class to instantiate a stack with
class Topping{
public:
   void input(){
      cout << "topping name: "; cin >> name_; 
      cout << "price$ "; cin >> price_; 
   }
   void output() const{
      cout << name_ << " $" << price_ << endl;
   }
private:
   string name_;
   int price_;
};

// functions using instantiated template 
// as a return value and as a parameter
Stack<char> fillCharStack(){
   char inChar;
   Stack<char> cs;
   cout << "Enter word: ";
   while ((inChar = cin.get()) != '\n')
      if (!cs.full()) cs.push(inChar);
   return cs;
}

void printCharStack(Stack<char> cs){
   cout << "Inverted word: ";
   while (!cs.empty())
      cout << cs.pop();
   cout << endl;
}

int main() {
   /*
   // character stack 
   // Stack<char,10> charStack;
   // using default value for stack size
   Stack <char> charStack; 

   charStack=fillCharStack();
   printCharStack(charStack);

   // object stack
   Stack<Topping> pizza;
   char another;
   do{
      Topping nextTop;
      nextTop.input();
      pizza.push(nextTop);
      cout << "Another? [y/n] ";
      cin >> another;
   }while(another=='y');

   if(cin.peek() == '\n')
      cin.get(); // clearing out trailing endline

   cout << "Toppings on your pizza\n";
   while(!pizza.empty()){
      pizza.pop().output();
   }
   */
  

   Stack<Stack<char>,5> pileOfStacks; 

   while(!pileOfStacks.full())
      pileOfStacks.push(fillCharStack());

   while(!pileOfStacks.empty())
      printCharStack(pileOfStacks.pop());
}
