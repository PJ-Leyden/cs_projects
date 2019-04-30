// demonstrating polymorphism and virtual functions
// Mikhail Nesterenko
// 1/28/2014

#include <iostream>

using std::cout; using std::endl;

// base class
class Figure {
public:
   Figure(int);
   /*
   virtual void draw() { cout << "Nothing of size " 
			      << size_ << endl;}
   */
   virtual void draw()=0;
   virtual ~Figure(){cout << "Base class destructor\n";}
protected:
   int size_;
};

// derived classes
class Square: public Figure{
public:
  Square(int);
   // void draw(int) override;
   void draw() override; // final;  
  ~Square(){ cout << "Square destructor\n";}
};

// derived classes
class EmptySquare: public Square{
public:
   EmptySquare(int);
   void draw(); 
};

class Triangle: public Figure{
public:
  Triangle(int);
  void draw() override;
  ~Triangle(){ cout << "Triangle destructor\n";}
};

// constructors
Figure::Figure(int size): size_(size){}
Square::Square(int size): Figure(size){}
EmptySquare::EmptySquare(int size): Square(size){}
Triangle::Triangle(int size): Figure(size){}

void Square::draw(){
  for(int i=0; i < size_; ++i){
    for(int j=0; j < size_; ++j)
      cout << '*';
    cout << endl;
  }
  cout << endl;
}


void EmptySquare::draw(){
  for(int i=0; i < size_; ++i){
    for(int j=0; j < size_; ++j)
       if(i==0 || j == 0 || i == size_-1 || j == size_-1)
	  cout << '*';
       else
	  cout << ' ';
    cout << endl;
  }
  cout << endl;
}


void Triangle::draw(){
  for(int i=0; i < size_; ++i){
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
    if(i % 2 == 0) 
      fig[i] = new Triangle(i+1);
    else 
      fig[i] = new Square(i+1);


  for(int i=0; i < num; ++i) // drawing all figures
    fig[i] -> draw();

  Figure *fp = new EmptySquare(5);
  fp -> draw();


  for(int i=0; i < num; ++i)
     delete fig[i];
}
