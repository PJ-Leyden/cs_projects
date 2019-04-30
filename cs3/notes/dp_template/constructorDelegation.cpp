// constructor delegation
// Mikhail Nesterenko
// 10/22/2017

#include <iostream>

using std::cout; using std::endl;

// base class
class Figure {
public:
   Figure():Figure(0){} // void constructor delegates 
                        // to regular constructor
   Figure(int size): size_(size){}

   void draw();
protected:
  int size_;
};


void Figure::draw(){
   if(size_ > 0)
      for(int i=0; i < size_; ++i){
	 for(int j=0; j < size_; ++j)
	    cout << '*';
	 cout << endl;
      }
   else
      cout << "nothing" << endl;
}

int main(){
   Figure empty, small(3), big(5);

   empty.draw();
   cout << endl;
   small.draw();
   cout << endl;
   big.draw();
}

