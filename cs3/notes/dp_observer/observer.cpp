// observer pattern, pull method
// Mikhail Nesterenko
// 11/11/2014

#include <set>
#include <iostream>
#include <string>


using std::string;
using std::set;
using std::cout; using std::endl;

//
// abstract classes describing the mechanism 
// of subscription and notification
// 

// class Subject; // forward class declaration

class Observer{
public:
   Observer(class Subject* s);
   virtual void notify() const = 0;
};


class Subject{
public: 
   void registerObserver(Observer *o)
                       {views_.insert(o);}
   void deregisterObserver(Observer *o)
                       {views_.erase(o);}
   void notifyObservers() const {
      for(auto e: views_) e->notify();}
private:
   set <Observer *> views_;
};


Observer::Observer(Subject *s){
   s->registerObserver(this);
}


//
// concrete classes describing the content 
// of subject/observer
//

class ConcreteSubject;

class ConcreteObserver: public Observer {
public:
   ConcreteObserver(const string &, ConcreteSubject*);
   void notify() const override;
private:
   string name_;
   ConcreteSubject *s_;
};

class ConcreteSubject: public Subject {
public:
   ConcreteSubject(const string &name): name_(name) {}
   void changeName(const string &name)
               {name_=name; notifyObservers();}
   const string& getName() const {return name_;}
private:
   string name_;
};


ConcreteObserver::ConcreteObserver(const string &name, 
				   ConcreteSubject* s):
      name_(name), s_(s), 
      Observer(static_cast<Subject*>(s)){}


void ConcreteObserver::notify() const {
   cout << "observer " << name_ << " reports "
	<< "subject changed name to: " << s_->getName() 
	<< endl;
}


int main() {
   ConcreteSubject subj("Billy");
   ConcreteObserver obOne("Joe", &subj), obTwo("Jane", &subj);

   subj.changeName("Will");
   subj.deregisterObserver(&obOne);
   subj.changeName("Bill");

   subj.deregisterObserver(&obTwo);
   subj.registerObserver(&obOne);
   subj.changeName("William");
}
