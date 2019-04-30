// demonstrates that pre-increment returns an l-value
// Mikhail Nesterenko
// 1/15/2014

#include <iostream>

int main(){
  int i=0;

  ++i = 22 + 5;

  int j = i++ - ++i; 

  std:: cout << j << std::endl;

  std::cout << ++--++i << std::endl;
}
