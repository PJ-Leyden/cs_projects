// algorithms with objects, member functions for callbacks
// Mikhail Nesterenko
// 4/6/2014

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using std::string; using std::vector;
using std::ostream; using std::cout; 
using std::endl;
using namespace std::placeholders;

class employee{
public:
   employee(int id, const string& name, double salary, int yrHire): 
      id_(id), name_(name), salary_(salary), yrHire_(yrHire) {}

   void payraise(double raise){salary_+=raise;}
   bool senior(int year) const {return yrHire_ <= year;};

   friend bool operator< (const employee&, const employee&);
   friend bool higherPaid (const employee&, const employee&);
   friend bool operator== (const employee&, const employee&);
   friend ostream& operator<< (ostream&, const employee&);

private:
   int id_;
   string name_;
   double salary_;
   int yrHire_;
};



bool operator<(const employee& left, const employee& right){
   return left.id_ < right.id_;
}

bool higherPaid (const employee& left, const employee& right){
   return left.salary_ > right.salary_;
}


bool operator==(const employee& left, const employee& right){
   return left.id_ == right.id_;
}


ostream& operator<< (ostream& out, const employee& e){
   out << e.id_ << '\t' << e.name_ << '\t' << e.salary_ << '\t' << e.yrHire_;
   return out;
}

int main(){
   vector <employee> payroll =
      {{123, "Mike", 2000., 2004},
       {345, "Charlie", 1500., 2012},
       {192, "Joe", 2100., 2010},
       {752, "Paul", 1100., 2013},
       {101, "Sue", 3300., 1998},
       {123, "Mark", 2500., 2600}};

   cout << "\npayroll\n";
   for(auto &e : payroll) cout << e << endl;

   // sort payroll

   sort(payroll.begin(), payroll.end());
   cout << "\nsorted\n";
   for(auto &e : payroll) cout << e << endl;

   // remove records with the same id
   /*
   auto last=unique(payroll.begin(), payroll.end());
   payroll.erase(last,payroll.end());
   */

   payroll.erase(
		 unique(payroll.begin(), payroll.end()), 
		 payroll.end());

   cout << "\nduplicates removed\n";
   for(auto &e : payroll) cout << e << endl;

   // give everyone a raise
   double raise=100.;
   for_each(payroll.begin(), payroll.end(), 
	    bind(&employee::payraise, _1, raise));
   cout << "\nafter raise\n";
   for(auto &e : payroll) cout << e << endl;

   // remove records with date of hire later than stated
   int yearHire=2010;
   payroll.erase(remove_if(payroll.begin(), payroll.end(), 
			 [=](employee const &e){
			    return !e.senior(yearHire);
			    }
			   ),
		 payroll.end());
   cout << "\nafter removing late hires\n";
   for(auto &e : payroll) cout << e << endl;   

   // custom sort by salary
   sort(payroll.begin(), payroll.end(), higherPaid);
   cout << "\nin the order of salaries\n";
   for(auto &e : payroll) cout << e << endl;
}
