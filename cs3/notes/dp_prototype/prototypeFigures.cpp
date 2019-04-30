// prototype pattern example
// Mikhail Nesterenko
// 2/18/2014

#include <iostream>
#include <vector>

using std::cout; using std::endl;

// base class
class Figure {
public:
   Figure(int size): size_(size){}
   void resize(int newSize){size_=newSize;}
   // method required for prototype pattern
   virtual Figure* clone() =0; 
   virtual void flip() =0;
   virtual void draw() =0;
   virtual ~Figure(){}
protected:
   int size_;
};

// enumeration class C++11 style
enum class Direction {Horizontal, Vertical};

class Line: public Figure{
public: 
   Line(int size, Direction dir): 
      dir_(dir), Figure(size){}

   // clone returns covariant type
   Line* clone() override 
          {return new Line(size_, dir_);}  

   void flip() override {
      dir_= dir_ == Direction::Horizontal ? 
	            Direction::Vertical : 
	            Direction::Horizontal;
   } 
   void draw() override {
      for(int i=0; i<size_; ++i){
	 cout << '*';
	 if(dir_ == Direction::Vertical) cout << endl;
      }
      if(dir_ == Direction::Horizontal) cout << endl;
   }
protected:
   Direction dir_;
};

class Square: public Figure{
public:
   Square(int size, char fill):fill_(fill),Figure(size){}

   Square* clone() override 
         {return new Square(size_, fill_);}

   void flip() override {} // flip does nothing to a square
   void draw() override{
      for(int i=0; i<size_; ++i){
	 for(int j=0; j<size_; j++)
	    cout << fill_;
	 cout << endl;
      }
   }
protected:
   char fill_;
};


int main(){
   // declares prototype objects
   Square prototypeSquare(3, '$'); 
   Line prototypeLine(5, Direction::Horizontal);
   std::vector<Figure*> figures; 

   const int figNum=10;

   for(int i=0; i<figNum; ++i) 
      if(i < 5)
	 figures.push_back(prototypeSquare.clone()); 
      else
	 figures.push_back(prototypeLine.clone());


   for(int i=0; i<figNum; ++i){
      figures[i]->draw(); // draw figures
      cout << endl;
   }

   for(int i=0; i<figNum; ++i) {
      figures[i]->resize(i+1); // resize all figures
      // flip every other one
      if(i % 2 == 0) figures[i] -> flip(); 
   }

   // draw figures
   for(int i=0; i<figNum; ++i) figures[i]->draw(); 

   // deallocate figures
   for(int i=0; i<figNum; ++i) delete figures[i]; 
}
