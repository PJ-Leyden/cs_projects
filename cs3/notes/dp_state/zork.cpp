// demonstrates state design pattern
// Mikhail Nesterenko
// 2/23/2014

#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

class State;

// context
class Character{
public:
   Character();

   // behaviors
   void skipLunch();
   void eat();
   string report();

   // part of implementation of state pattern
   void changeState(State* s){state_=s;}
private:
   State* state_;
};

// absract state
class State{
public:
   // provides default implementation
   virtual void skipLunch(Character*){} 
   // provides default implementation
   virtual void eat(Character*){}  
   virtual string report() =0;
   void changeState(Character* c, State* s){
      c->changeState(s);
   }
};

class Full: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Full;
      return onlyInstance;
   }
   void skipLunch (Character *c) override;
   void eat (Character *c) override;
   string report() override {return "full";}
private:
   // here and elsewhere should be stated private constructor/assignment
   // to correctly implement singleton, skipped to simplify code
};


class Hungry: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Hungry;
      return onlyInstance;
   }
   void skipLunch(Character *c) override;
   void eat(Character *c) override;
   string report() override {return "hungry";}
};


class Dead: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Dead;
      return onlyInstance;
   }
   string report() override {return "dead";}
};

// state transitions member functions
// Full
void Full::skipLunch(Character *c) 
         {changeState(c, Hungry::instance());} 
void Full::eat(Character *c)
         {changeState(c, Dead::instance());}

// Hungry
void Hungry::eat(Character *c)
            {changeState(c, Full::instance());}
void Hungry::skipLunch(Character *c)
            {changeState(c, Dead::instance());}


// Character member functions
Character::Character(){state_=Full::instance();}

// handles/behaviors
void Character::skipLunch(){state_->skipLunch(this);}
void Character::eat(){state_->eat(this);}
string Character::report(){return state_->report();}

int main(){
   Character zork;
   cout << "Zork is " << zork.report() << endl;

   while(zork.report() != "dead"){
      cout << "What would you like Zork to do? Eat or skip lunch? [e/s] ";
      char action; cin >> action;
      if(action == 'e')
	 zork.eat();
      else
	 zork.skipLunch();
      cout << "Zork is " << zork.report() << endl;
   }

   // demonstrates that two Characters may be in two different states
   Character grue;
   cout << "Zork is " << zork.report() << " while "
        << "Grue is " << grue.report() << endl;
}
