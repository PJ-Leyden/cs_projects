// operational algorithm for_each
// Mikhail Nesterenko, adapted from Pro C++
// 3/30/2014

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;

// populates vector
void populateContainer(vector<char>& v){
   cout << "enter characters, '0' to quit: ";
   while (true) {
      char item;
      cin >> item;
      if (item == '0') break;
      v.push_back(item);
   }
}

int main(){
   vector<char> myVector; populateContainer(myVector);
   
   // using lambda to accumulate string
   string result="";
   for_each(myVector.cbegin(), myVector.cend(),
	    [&](char c){
	       // concatenate and space elements
	       result +=c;  
	       result +=',';
	    });
   
   cout << "You entered: " << result << endl;
}
