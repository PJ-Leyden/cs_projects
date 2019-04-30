// simple inheritance demonstration
// Mikhail Nesterenko
// 1/28/2014

#include <iostream>

using std::cout; using std::endl;

// base class
class Figure {
public:
  Figure(int);

protected:
  int size_;
};

// derived class
class Square: public Figure{
public:
  Square(int);
  void draw();  
};

Figure::Figure(int size): size_(size){}

Square::Square(int size): Figure(size){}

void Square::draw(){
  for(int i=0; i < size_; ++i){
    for(int j=0; j < size_; ++j)
      cout << '*';
    cout << endl;
  }
}

int main(){
   Square small(3), big(5);
   small.draw();
   cout << endl;
   big.draw();
}

