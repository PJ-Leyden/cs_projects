// unordered set/multiset example
// Mikhail Nesterenko
// 3/18/2014

#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using std::cout; using std::endl;
using std::unordered_set; using std::unordered_multiset;

int main () {
   unordered_set<char> mySet;
   unordered_multiset<char> myMset;

   srand(time(nullptr));
   for(int i=0; i < 30; ++i){
      // selecting random characters
      char newChar = 'a' + rand()%5; 
      mySet.insert(newChar); 
      myMset.insert(newChar);
   }

   // print content
   cout << "elements in mySet:" << endl;
   for(auto& e: mySet) cout << e << ' '; cout << endl;

   cout << "elements in myMSet:" << endl;
   for(auto& e: myMset) cout << e << ' '; cout << endl;

   // average number of elements per bucket
   cout << "hash parameters: \t mySet \t myMSet" << endl;

   // number of buckets in container
   cout << "load factor: \t" << mySet.load_factor() << "\t" << myMset.load_factor() << endl; 
   cout << "bucket count: \t" << mySet.bucket_count() << "\t" << myMset.bucket_count() << endl;
   // bucket for character 'a'
   cout << "bucket for 'a': \t" << mySet.bucket('a') << "\t" << myMset.bucket('a') << endl;
}
