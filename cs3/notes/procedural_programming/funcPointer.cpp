// using function returning pointer
// Mikhail Nesterenko
// 1/19/2014

#include <iostream>

using std::cout;

int* getElement(int x[], int i) {
  return &x[i];
} 


int main(){
  int a[] = {10,20,30};

  cout << *getElement(a, 1);
  *getElement(a, 2) = 55;
  cout << *getElement(a,2);
}
