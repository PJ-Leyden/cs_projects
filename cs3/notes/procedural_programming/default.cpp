// demonstrates default parameter values
// Mikhail Nesterenko
// 1/21/2016

#include <iostream>
using std::cout; using std::endl;


void move(int from, int to=0, int by=0);

int main(){
   move(1, 2, 3);
   move(10, 20);
   move(100);
   // move();
}


void move(int from, int to, int by){
   cout << "from = " << from 
        << ", to = " << to
        << ", by = " << by << endl;
}
