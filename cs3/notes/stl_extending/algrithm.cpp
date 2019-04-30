// custom algorithm
// Mikhail Nesterenko
// 4/6/2014

#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <ctime>

using std::vector;
using std::cout; using std::endl;

template <typename InputIterator, 
	  typename Predicate>
vector<InputIterator> find_all
               (InputIterator first, 
                InputIterator last, 
		Predicate pred){
   vector<InputIterator> res;
   for(auto found = find_if(first, 
			    last, 
			    pred);
       found != last; 
       found=find_if(++found, last, pred))
      res.push_back(found);
   return res;
}

int main(){
   srand(unsigned(time(nullptr)));
   vector<int> vec(rand()%30);
   generate(vec.begin(), 
	    vec.end(), 
	    [](){return rand()%10;});

   cout << "generated elements: "; 
   for(auto e: vec){cout << e << " ";} 
   cout << endl;

   auto all = find_all(vec.begin(), 
	      vec.end(), 
	      [](int i){return i>5;});

   cout << "found " << all.size() << 
        " matching elements at positions: ";
   for (auto it : all) {
      cout << "element: " << *it;
      cout << " position: " 
	   << it - vec.begin() << endl; 
   }
}
