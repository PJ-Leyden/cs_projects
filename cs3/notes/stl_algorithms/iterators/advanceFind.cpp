// STL find algorithm
// Mikhail Nesterenko
// 3/18/2014

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::cout; using std::endl; using std::cin;
using std::vector; using std::list;

int main(){
   srand(time(nullptr));
   // vector <int> cont;
   list <int> cont;

   for(int i=0; i < 20; ++i) cont.push_back(rand()%10);

   cout << "Enter the number to find: ";
   int num; cin >> num;

   auto it=find(cont.begin(), cont.end(), num);

   if(it != cont.end()){
      cout << "Found it at position(s): ";
      do{
	 cout << distance(cont.begin(), it) << " ";
	 advance(it,1); // extraneous, increment works
	 // it = next(it, 1); // also extraneous
         it = find(it, cont.end(), num);
      }while(it != cont.end());
   }else
      cout << "Not found it ";

   cout << "in conainer ";
   for(auto e: cont) cout << e << " ";
   cout<< endl;
}
