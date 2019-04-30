// using sorting algorihtms to demonstrate Strategy Design Pattern
// Mikhail Nesterenko
// 11/16/2014

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using std::cout; using std::endl;
using std::vector; 

class OrderedCollection;

// abstract strategy
// strategy interface, pull method
class Sorter{
public:
   Sorter(OrderedCollection *oc): oc_(oc) {}
   virtual void sort() const = 0;
protected:
   OrderedCollection *oc_; // reference to context
};


// shorthand for a vector iterator
typedef vector<int>::iterator It;  

// context using the strategies
class OrderedCollection{
public:
   void setRange(It begin, It end)
        {begin_ = begin; end_ = end;}
   void setSorter(Sorter *sorter) {sorter_ = sorter;}
   It begin() const {return begin_;}
   It end()  const {return end_;}
   void sort() {sorter_->sort();}
private:
   It begin_;
   It end_;
   Sorter *sorter_; 
};


// concrete strategy using bubble sort
class BubbleSorter: public Sorter {
public:
   BubbleSorter(OrderedCollection *oc): Sorter(oc){}
   void sort() const {
      bool swapped;
      do{
	 swapped = false;
	 for(It one=oc_->begin(), two = ++(oc_->begin()); 
	     two != oc_->end();
	     ++one, ++two)
	    if(*one > *two){
	       std::swap(*one, *two);
	       swapped=true;
	    }
      }while(swapped);
   }
};


// concrete strategy using STL sorting alg
class StdSorter: public Sorter{
public:
   StdSorter(OrderedCollection *oc): Sorter(oc){}
   void sort() const{
      std::sort(oc_->begin(), oc_->end());
   }
};




int main() {
   vector<int> v={3,2,1,0}, vc=v;

   OrderedCollection sortedVector;
   StdSorter ss(&sortedVector);
   BubbleSorter bs(&sortedVector);

   // 
   // sorting short vectors to demo correctness
   //

   // STL sorter
   sortedVector.setSorter(&ss);
   sortedVector.setRange(v.begin(), v.end());

   for(auto e: v) cout << e << " "; cout << endl;
   sortedVector.sort();
   cout << "STL sorted" << endl; 
   for(auto e: v) cout << e << " "; cout << endl << endl;

   // BubbleSort sorter
   sortedVector.setSorter(&bs);
   sortedVector.setRange(vc.begin(), vc.end());

   for(auto e: vc) cout << e << " "; cout << endl;
   sortedVector.sort();
   cout << "bubble sorted" << endl; 
   for(auto e: vc) cout << e << " "; cout << endl << endl;
  

   // 
   // sorting large vectors to demo performance
   // 
   v.clear();
   srand(time(nullptr));
   std::generate_n(back_inserter(v),20000,
		   []{return rand()%100;});
   vc=v;

   std::chrono::time_point<std::chrono::high_resolution_clock> 
      startTime, endTime; // chrono time points
   std::chrono::duration<double> duration; 
                          // chrono time interval

   // STL sorter
   sortedVector.setRange(v.begin(), v.end());
   sortedVector.setSorter(&ss);

   startTime = std::chrono::high_resolution_clock::now();
   sortedVector.sort();
   endTime = std::chrono::high_resolution_clock::now();
   duration = endTime - startTime;

   cout << "standard sort ran for " << duration.count() << " seconds" << endl;

   // bubble sort
   sortedVector.setRange(vc.begin(), vc.end());
   sortedVector.setSorter(&bs);

   startTime = std::chrono::high_resolution_clock::now();
   sortedVector.sort();
   endTime = std::chrono::high_resolution_clock::now();
   duration = endTime - startTime;
   cout << "bubble sort ran for " << duration.count() << " seconds" << endl;

   // confirming sorted vectors are the same
   if(v == vc)
      cout << "sorted vectors are the same" << endl;
   else
      cout << "sorted vectors are different" << endl;
   
}
