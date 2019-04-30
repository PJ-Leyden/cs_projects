// vector space allocation functions
// Mikhail Nesterenko
// 3/11/2014

#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::cin; using std::endl;

int main(){

   vector<int> vect;
   vect.resize(3);
   vect.reserve(6);
   
   cout << "Enter maximum size: ";
   int size; cin >> size;
   cout << "last value \t size \t capacity" << endl;

   for(int i=3; i < size; ++i){
      vect.push_back(i);
      cout << vect.back() << "\t\t" 
	   << vect.size() << "\t\t" 
	   << vect.capacity() << endl;
   }

   while(vect.size() > 0) {
      cout << vect.back() << "\t\t" 
	   << vect.size() << "\t\t" 
	   << vect.capacity() << endl;
      vect.pop_back();
   }
}
