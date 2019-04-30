// STL find_if algorithm, using function pointer as a callback
// Mikhail Nesterenko
// 3/18/2014

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::cout; using std::endl; using std::cin;
using std::vector;

bool passingScore(int s){
   const int threshold=50;
   return s>=threshold;
}

int main(){
   // declaring a function pointer variable
   // bool (*fp)(int) = passingScore;
   auto fp = passingScore;

   srand(time(nullptr));
   vector <int> vect;

   for(int i=0; i < 10; ++i) vect.push_back(rand()%100);

   auto it=find_if(vect.begin(),vect.end(), fp);

   if(it != vect.end()){
      cout << "Found it at position(s): ";
      do{
         cout << it - vect.begin() << " ";
         it=find_if(it+1, vect.end(), fp);
      }while(it != vect.end());
   }else
      cout << "Not found it ";


   cout << "in vector ";
   for(auto e: vect) cout << e << " ";
   cout<< endl;
}
