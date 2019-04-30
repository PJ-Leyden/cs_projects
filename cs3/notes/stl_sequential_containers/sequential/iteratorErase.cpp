// iterator-based vector modification
// Mikhail Nesterenko
// 3/11/2014

#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main(){
   vector<int> vOne, vTwo;

   for(int i=0; i<5; ++i) {
      vOne.push_back(i);
      vTwo.insert(vTwo.begin()+i,i+5);
   }

   // appending one vector to end of another
   vOne.insert(vOne.end(), vTwo.begin(), vTwo.end()-2); 
   // vOne.assign(vTwo.begin(), vTwo.end()-2);

   vOne.erase(vOne.begin()+5, vOne.end()-2);  

   // adding four 10-s
   vOne.insert(vOne.begin()+5, 4, 10); 

   // erasing the contents of the vector
   // vOne.erase(vOne.begin(), vOne.end());
   vOne.clear(); 



   for(auto it=vTwo.begin(); 
       it != vTwo.end();)
      if (!(*it % 2))
	 it = vTwo.erase(it);
      else
	 ++it;

   cout << "vOne: ";
   for(auto e: vOne) cout << e; cout << endl;
  
   cout << "vTwo: ";
   for(auto e: vTwo) cout << e; cout << endl;

}
