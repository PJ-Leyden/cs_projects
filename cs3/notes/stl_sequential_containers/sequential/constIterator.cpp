// const iterator demo
// Mikhail Nesterenko
// 3/11/2014

#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main(){
   vector<int> intVector(10, 55);
   for(vector<int>::const_iterator it=intVector.begin(); 
       it != intVector.end(); ++it){
      cout << *it << endl;
   }
cout<< endl;
  
   for(auto it=intVector.cbegin(); 
       it != intVector.cend(); 
       ++it)
      cout << *it << " ";
   cout << endl;
  
}
