// advance and distance iterator functions
// Mikhail Nesterenko
// 4/8/2014

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <ctime>

using std::vector; using std::list;
using std::cout; using std::cin; using std::endl;


template <typename container>
void skip(const container& cont){
   int step=0;
   auto it=cont.cbegin();
   while(step < distance(it, cont.cend())){
      advance(it, step);
      cout << "advanced to element: "
	   << distance(cont.cbegin(), it)
	   << " value: " << *it << endl;
      step = rand()%6+1;
   }
}

int main () {
   srand(unsigned(time(nullptr)));
   vector<int> v(rand()%30);
   list<int> el(v.size());

   // populate containers
   generate(v.begin(), v.end(), [](){return rand()%10;});
   copy(v.cbegin(), v.cend(), el.begin());
   cout << "Both containes hold: "; 
   for(auto e : el) cout << e << ' '; cout << endl;

   cout << "Stepping through vector" << endl;
   skip(v);
   cout << endl;

   cout << "Stepping through list" << endl;
   skip(el);
}

