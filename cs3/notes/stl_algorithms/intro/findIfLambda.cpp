// STL find_if algorithm, using lambda as callback
// Mikhail Nesterenko
// 3/18/2014

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::cout; using std::endl; 
using std::cin;
using std::vector;

int main(){
   srand(time(nullptr));
   vector <int> vect;

   for(int i=0; i < 10; ++i)
      vect.push_back(rand()%100);

   cout << "Enter passing score: ";
   int score; 
   cin >> score;

   // passingScore is a function 
   // pointer(ish), that is
   
   auto passingScore = 
      [=](int i) {return i >= score;};
  
   
   auto it=find_if(vect.begin(),vect.end(), 
	  [=](int i) {return i >= score;}
	 );
  
   /*
   auto it=find_if(vect.begin(),vect.end(),
		   passingScore);
   */

   if(it != vect.end()){
      cout << "Found it at position(s): ";
      do{
         cout << it - vect.begin() << " ";
	 it=find_if(it+1,vect.end(), 
		    passingScore);
      }while(it != vect.end());
   }else
      cout << "Not found it ";

   cout << "in vector ";
   for(auto e: vect) cout << e << " ";
   cout<< endl;
}

