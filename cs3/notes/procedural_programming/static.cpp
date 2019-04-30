// demonstates the operation of a static variable
// Mikhail Nesterenko
// 1/19/2014

#include <iostream>

using std::cout; using std::endl;

void login() {
  int number1 = 0;
  static int number2 = 0;
  ++number1; ++number2; 
  cout << number1 << number2 << endl;
} 


int main(){
  login();
  login();
  login();
}
