// demonstrating copy and swap idiom for copy costructor
// Mikhail Nesterenko
// 1/21/2014

#include <iostream>

using std::cout; using std::endl;


class MyArray{
public:
  // regular and default constructor
  MyArray(int size=0){size_= size; array_= size>0 ? new int[size] : nullptr;}

  // copy constructor
  MyArray(const MyArray& other){
    size_=other.size_;

    array_ = size_>0 ? new int[size_] : nullptr;
    std::copy(other.array_, other.array_ + size_, array_);
  }

  // destructor
  ~MyArray(){ delete[] array_;}



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


  friend void swap(MyArray& first, MyArray& second){
     std::swap(first.size_,  second.size_);
     std::swap(first.array_, second.array_);
  }

  // assignment overloading using copy-and-swap idiom
  MyArray& operator=(MyArray other){ // note pass-by-value parameter
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
  int *array_;
  int size_;
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
