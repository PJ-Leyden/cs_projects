// figures: template method programming pattern example
// Mikhail Nesterenko
// 1/28/2014

#include <iostream>

using std::cout; using std::endl;

// base class
class Figure {
public:
  Figure(int size=0, int origin=0);
  virtual void draw() =0; // pure virtual function
                          // primitive
                          // operation in the 
                          // template method

  // template methods
  void alignLeft(){origin_=0; draw();}
  void alignRight(){origin_=ScreenSize-size_; draw();}
  void alignCenter(){origin_=(ScreenSize-size_)/2; 
                    draw();}

  virtual ~Figure(){}

protected:
  const int ScreenSize=50;
  int size_;
  int origin_;
};


// derived classes
class Square: public Figure{
public:
  Square(int);
  void draw() override; 
};

class Triangle: public Figure{
public:
  Triangle(int);
  void draw() override;
};

// constructors
Figure::Figure(int size, int origin): 
   size_(size), origin_(origin){}

Square::Square(int size): Figure(size){}
Triangle::Triangle(int size): Figure(size){}

void Square::draw(){
  for(int i=0; i < size_; ++i){
    for(int j=0; j < origin_; ++j)
      cout << ' ';
    for(int j=0; j < size_; ++j)
      cout << '*';
    cout << endl;
  }
  cout << endl;
}


void Triangle::draw(){
  for(int i=0; i < size_; ++i){
    for(int j=0; j < origin_; ++j)
      cout << ' ';
    for(int j=0; j < size_; ++j)
      if(j <= i) cout << '*';
    cout << endl;
  }
  cout << endl;
}

int main(){
  const int num=10; // number of figures to draw
  Figure *fig[num]; // array of pointers to figures

  for(int i=0; i < num; ++i) // initialization
    if(i % 2 !=0)// odd are triangles
      fig[i] = new Triangle(i+1);
    else// even are squares
      fig[i] = new Square(i+1);

  /*  
  for(int i=0; i < num; ++i) 
     fig[i] -> alignCenter(); // calling template method
  */                         // to draw figures in the center

  for(int i=0; i < num; ++i) 
     fig[i] -> alignRight(); // calling template method
                             // to draw figures in the right

}
