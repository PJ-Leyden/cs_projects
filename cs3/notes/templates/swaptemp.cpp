// function template to swap two values
// Walt Savitch
// 04/27/00

#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;
// using std::swap;



// interchanges the values of variable1 and variable2.  
template<typename T> 
void swap(T& variable1, T& variable2) {
    const T temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

/*
void swap(int& variable1, int& variable2) {
   int temp = variable1;
   variable1 = variable2;
   variable2 = temp;
   cout << "Hello World!!!\n";
}
*/

int main() {
    // swaps integers
    int integer1 = 1, integer2 = 2;
    cout << "Original integer values are "
         << integer1 << " " << integer2 << endl;
    swap(integer1, integer2);
    cout << "Swapped integer values are "
         << integer1 << " " << integer2 << endl;

    // swaps chars
    char symbol1 = 'A', symbol2 = 'B';
    cout << "Original character values are "
         << symbol1 << " " << symbol2 << endl;
    swap(symbol1, symbol2);
    cout << "Swapped character values are "
         << symbol1 << " " << symbol2 << endl;

    // swaps strings
    string str1="one", str2 ="two";
    cout << "Original string values are "
         << str1 << " " << str2 << endl;
    swap(str1, str2);
    cout << "Swapped string values are "
         << str1 << " " << str2 << endl;
}
