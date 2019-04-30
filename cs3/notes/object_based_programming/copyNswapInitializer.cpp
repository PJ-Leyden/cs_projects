// demonstrating copy and swap idiom for copy costructor
// using initializers
// Mikhail Nesterenko
// 1/21/2014

#include <iostream>

using std::cout; using std::endl;

// constructor with initializer list
// could be invoked as MyArray m, n(55);
class MyArray{
public:
  MyArray(int size=0): 
     size_(size), 
     array_(new int[size]) 
  {}

  // copy constructor
  MyArray(const MyArray& other) :
    size_(other.size_),   // initialization list
    array_(size_>0 ? new int[size_] : nullptr) {
    std::copy(other.array_, other.array_ + size_, array_);
  }

  // destructor
  ~MyArray(){ delete[] array_;}

  /*
  // "standard" assignment overloading
  MyArray& operator=(const MyArray& other){
    if (this != & other){ // protection against self assingment
      delete [] array_;
      size_ = other.size_;
      array_ = size_>0 ? new int[size_]: nullptr;
      std::copy(other.array_, other.array_ + size_, array_);
    }
    return *this;
  }
  */

  friend void swap(MyArray& first, MyArray& second){
    std::swap(first.size_,  second.size_);
    std::swap(first.array_, second.array_);
  }

  // assignment overloadin using copy-and-swap idiom
  // note pass-by-value parameter
  MyArray& operator=(MyArray other){ 
    swap(*this, other);
    return *this;
  }

   void printArray(){
      for(int i=0; i < size_; ++i) cout << array_[i] << ' ';
      cout << endl;
   }

   void assignArray(int n){
      for(int i=0; i < size_; ++i) array_[i] = n;
   }


private:
  int size_;
  int *array_;
};


// standalone function
void otherFunc(MyArray newArray){ // copy constructor invoked
   cout << "newArray: "; newArray.printArray();
   newArray.assignArray(66);
   cout << "newArray modified: "; newArray.printArray();
}

int main(){
   MyArray ob1(5), ob2;
   ob1.assignArray(55);

   otherFunc(ob1);

   ob2 = ob1; // overloaded assingment invoked
   cout << "ob2: "; ob2.printArray();
}


