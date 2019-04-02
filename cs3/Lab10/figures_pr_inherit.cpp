// private inheritance, 
// brings feature into interface of derived class with "using"
// Mikhail Nesterenko
// 2/16/2014

#include <iostream>

using std::cout; using std::endl;

// base class
class Figure {
public:
   Figure(int size): size_(size){}
   int findCenter(){return size_/2;}
protected:
   int size_;
};

// derived class
class Square: private  Figure{
public:
   Square(int size): Figure(size){}

   void draw(){
      for(int i=0; i < size_; ++i){
	 for(int j=0; j < size_; ++j)
	    cout << '*';
	 cout << endl;
      }
   }
   using Figure::findCenter; 
};

int main(){
   Square small(3), big(6);
   small.draw();
   cout << "Center of the small square is: " 
	<< small.findCenter() << endl;

   big.draw();
   cout << "Center of the big square is: " 
	<< big.findCenter() << endl;
}
