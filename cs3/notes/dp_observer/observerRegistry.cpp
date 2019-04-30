// observer pattern using a signup registry
// Mikhail Nesterenko
// 4/22/2014

#include <set>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using std::cout; using std::endl;
using std::map; using std::set;
using std::string;

class Observer;
class Subject;

class EventRegistry{
public:
   static void registerObserver(Subject*, Observer*);
   static void deregisterObserver(Subject*, Observer*);
   static void handleMessage(Subject*);
private:
   static map<Subject*, set<Observer*>> observerMap_;
};


// initialize the static map
map<Subject*, set<Observer*>> 
              EventRegistry::observerMap_;


class Observer{
public:
   Observer(const string &name): name_(name) {}
   string getName() const {return name_;}
   void subscribe(Subject *s){
      EventRegistry::registerObserver(s, this);}
   void unsubscribe(Subject *s){
      EventRegistry::deregisterObserver(s, this);}
   void handleMessage(Subject*);
private:
   string name_;
};

class Subject{
public:
   Subject(const string &name): name_(name) {}
   string getName() const {return name_;}
   void generateMessage(){
      cout << name_ << " sent a message" << endl;
      EventRegistry::handleMessage(this);}
private:
   string name_;
};

void EventRegistry::registerObserver
             (Subject *s, Observer* o){
   observerMap_[s].insert(o);
   cout << o->getName() << " subscribed to " 
	<<  s->getName() << endl;
}

void EventRegistry::deregisterObserver
            (Subject *s, Observer* o){
   observerMap_[s].erase(o);
   cout << o->getName() << " unsubscribed from " 
	<<  s->getName() << endl;
}

void EventRegistry::handleMessage(Subject *s){
   for (auto e: observerMap_[s])
      e->handleMessage(s);
}

void Observer::handleMessage(Subject *s) {
   cout << name_ << " received message from " 
	<< s->getName() << endl;
}


int main() {
   Observer o1("Observer One"), o2("Observer Two");
   Subject  s1("Subject One"),  s2("Subject Two");

   o1.subscribe(&s1); o2.subscribe(&s2);
   o2.subscribe(&s1);

   cout << endl;

   s1.generateMessage();
   s2.generateMessage();
   
   cout << endl;

   o2.unsubscribe(&s1);
   s1.generateMessage();

}
