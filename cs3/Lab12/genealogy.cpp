// traversing genealogical tree using Composite and Visitors
// Mikhail Nesterenko
// 10/28/2015

#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl;
using std::string; 
using std::vector;

class Person{ // component
public:
   Person(string firstName, 
	  Person *spouse, 
	  Person *father, 
	  Person *mother):
	  firstName_(firstName), spouse_(spouse), 
	  father_(father), mother_(mother){}
   string getFirstName(){return firstName_;}
   Person *getSpouse(){return spouse_;}
   void setSpouse(Person *spouse){spouse_=spouse;}
   Person *getFather(){return father_;}

   virtual void accept(class PersonVisitor *)=0;  
   virtual ~Person(){}
private:
   string firstName_;
   Person *spouse_;
   Person *father_;
   Person *mother_;
};

// composites

// man has a last name 
class Man: public Person{
public:
   Man(string lastName, 
	   string firstName, 
	   Person *spouse, 
	   Person *father, Person *mother): 
	  lastName_(lastName), 
	  Person(firstName, spouse, father, mother){}
   string getLastName(){return lastName_;}
   void accept(class PersonVisitor *visitor) override;
private:
   string lastName_;
};

// woman has a list of children
class Woman: public Person{
public: 
   Woman(vector<Person *> children, 
	   string firstName, 
	   Person *spouse, 
	   Person *father, Person *mother): 
	   children_(children),
	   Person(firstName, spouse, father, mother){}
   const vector<Person *> & getChildren()
						  {return children_;}
   void setChildren(const vector<Person *> &children)
							  {children_ = children;}
   void accept(class PersonVisitor *visitor) override;
private:
   vector<Person *> children_;
}; 

// abstract visitor
class PersonVisitor{
public:
   virtual void visit(Man*)=0;
   virtual void visit(Woman*)=0;
   virtual ~PersonVisitor(){}
};

// composite methods that define traversal
void Man::accept(PersonVisitor *visitor)
					{visitor->visit(this);}

void Woman::accept(PersonVisitor *visitor){ 
   // children traversal through mother only
   // father's children are not traversed so as not 
   // to traverse them twice: for mother and father

   visitor->visit(this);
   // traversing descendants
   for(auto child : children_) 
	  child->accept(visitor);
}

// concrete visitors
// the last name for a man is stored in object
// the last name a woman is determined by her 
// spouse if she is married
// or by her father if she is not
class NamePrinter: public PersonVisitor{
public:
	void visit(Man *m) override {
		cout << m->getFirstName() << " " 
		<< m->getLastName() << endl;
	}
	void visit(Woman *w) override {
		cout << w->getFirstName() << " ";
		if (w->getSpouse() != nullptr)
			cout << static_cast<Man *>(w->getSpouse())->getLastName();
		else if (w->getFather() != nullptr)
			cout << static_cast<Man *>(w->getFather())->getLastName();
		else
			cout << "Doe";
		cout << endl;
	}
};

class MadienPrinter: public PersonVisitor{
public:
	void visit(Man *m) override {
		//cout << m->getFirstName() << " " << m->getLastName() << endl;
	}
	void visit(Woman *w) override {
		cout << w->getFirstName() << " ";
		if (w->getFather() != nullptr){
			cout << static_cast<Man *>(w->getFather())->getLastName();
		}else{
			cout << "No Last Name";
		}
		cout << endl;
	}
};


class ChildrenPrinter: public PersonVisitor{
public:
   void visit(Man *m) override {
	  cout << m->getFirstName() << ": ";
	  Woman *spouse = static_cast<Woman *>
						 (m->getSpouse());
	  if(spouse != nullptr)
	 printNames(spouse->getChildren());
	  cout << endl;
   }
   void visit(Woman *w) override {
	  cout << w->getFirstName() << ": ";
	  printNames(w->getChildren());
	  cout << endl;
   }
private:
   void printNames(const vector<Person *> &children){
	  for(const auto c: children)
	 cout << c->getFirstName() << ", ";
   }
};


// demonstrating the operation
int main(){

   // setting up the genealogical tree      
   // the tree is as follows
   //    
   //
   //      James Smith     <--spouse-->   Mary 
   //	                                  |
   //	                               children ---------------------------
   //	                                  |              |                |
   //	                                  |              |                |
   //	   William Johnson <--spouse->    Patricia    Robert Smith      Linda
   //	                                  |
   //	                               children--------------
   //	                                  |                 |
   //                                     |                 |
   //	   Jennifer        <--spouse-->   Michael Johnson   Barbara
   //	       |
   //	     children
   //	       |
   //          |
   //	     Susan


   // first generation
   Man *js = new Man("Smith", "James", nullptr, nullptr, nullptr);
   Woman *ms = new Woman({}, "Mary", nullptr, nullptr, nullptr);
   ms->setSpouse(js); js->setSpouse(ms);


   // second generation
   Woman *ps = new Woman({}, "Patricia", nullptr, js, ms);
   Man *wj = new Man("Johnson", "William", nullptr, nullptr, nullptr);
   ps->setSpouse(wj); wj->setSpouse(ps);

   vector<Person *> marysKids  = {ps,
					  new Man("Smith", "Robert", nullptr, js, ms),
					  new Woman({}, "Linda", nullptr, js, ms)};
   ms->setChildren(marysKids);

   // third generation
   Man *mj = new Man("Johnson", "Michael", nullptr, wj, ps);
   vector<Person *> patsKids   = {mj,
								  new Woman({}, "Barbara", nullptr, wj, ps)}; 
   ps->setChildren(patsKids);

   Woman *jj = new Woman({}, "Jennifer", nullptr, nullptr, nullptr);
   vector<Person *> jensKids = {new Woman({}, "Susan", nullptr, mj ,jj)};

   jj->setSpouse(mj); mj->setSpouse(jj);
   jj->setChildren(jensKids);
   

   //

   MadienPrinter *mp = new MadienPrinter;

  ms->accept(mp);

}
