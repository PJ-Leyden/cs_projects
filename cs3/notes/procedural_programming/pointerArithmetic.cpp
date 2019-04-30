// pointer arithmetic example
// Mikhail Nesterenko
// 2/10/2016

#include <iostream>
using std::cout; using std::endl;

int mysteryFunc(char *str){
   char *e=str;
   while(*e++);
   return e-str;
}

void mysteryFunc2(char *str2, char *str1){
   while(*str2++ = *str1++);
}

int main(){
   char s1[] = "Hello, World!";
   cout << mysteryFunc(s1) << endl;

   char *s2 = new char[mysteryFunc(s1)];

   mysteryFunc2(s2, s1);
   cout << s2 << endl;
}
