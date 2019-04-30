// STL find_if algorithm, using function pointer as a callback
// Mikhail Nesterenko
// 3/18/2014

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout; using std::endl; using std::cin;
using std::vector;
using namespace std::placeholders;

bool passingScore(int s, int threshold){
   return s>=threshold;
}

int main(){
   srand(time(nullptr));
   vector <int> vect;

   for(int i=0; i < 10; ++i) 
      vect.push_back(rand()%100);
   /*
   auto it=find_if(vect.begin(), 
		   vect.end(), 
 	      bind(passingScore, _1, 70));
   */
   // auto it=find_if(vect.begin(), vect.end(),[](int x){return x >=50;});

   auto it = find_if
      (vect.begin(), vect.end(), 
       bind(std::greater_equal<int>(), 
	    _1, 70));

   if(it != vect.end()){
      cout << "Found it at position(s): ";
      do{
         cout << it - vect.begin() << " ";
	 /*
         it=find_if(it+1,vect.end(), 
	       bind(passingScore, _1, 70));
	 */
	 it = find_if(it+1, vect.end(), bind(std::greater_equal<int>(), _1, 50));
      }while(it != vect.end());
   }else
      cout << "Not found it ";


   cout << "in vector ";
   for(auto e: vect) cout << e << " ";
   cout<< endl;
}
