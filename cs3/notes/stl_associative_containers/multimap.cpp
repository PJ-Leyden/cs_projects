// multimap examples
// Mikhail Nesterenko
// 3/16/2014

#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>

using std::cout; using std::endl;
using std::make_pair; using std::multimap;


int main () {
   multimap<char,int> myMM;
   srand(time(nullptr));


   for(int i=0; i < 10; ++i)
      myMM.insert(make_pair('a'+ rand()%5, 
			    rand()%100)); 

   // myMM['a']=55; // not allowed

   // print content
   cout << "elements in myMM:" << endl;
   for(const auto& e: myMM) 
      cout << e.first << "\t" << e.second << endl;

  
   cout << "all elements in myMM with key 'a'" << endl;
   for(auto it=myMM.lower_bound('a'); 
            it != myMM.upper_bound('a'); ++it)
      cout << it->first << "\t" << it->second << endl;

   auto it = myMM.find('a');
   while (it != myMM.end()){
      myMM.erase(it);
      it = myMM.find('a');
   }

   // erasing all elements with key 'b'
   myMM.erase('b');

   // print content
   cout << "elements in myMM:" << endl;
   for(const auto& e: myMM) 
      cout << e.first << "\t" << e.second << endl;
}
