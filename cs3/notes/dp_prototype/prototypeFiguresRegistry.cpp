// prototype pattern with factory as registry
// Mikhail Nesterenko
// 11/05/2017

#include <iostream>
#include <vector>
#include <map>

using std::cout; using std::endl;

// enumeration class C++11 style
enum class Direction {Horizontal, Vertical};

// base class
class Figure {
public:
   Figure(int size, Direction dir): 
      size_(size), dir_(dir) {}
   void resize(int newSize){size_=newSize;}
   // method required for prototype pattern
   virtual Figure* clone() =0; 
   void flip(){
      dir_= dir_ == Direction::Horizontal ? 
	            Direction::Vertical : 
	            Direction::Horizontal;
   } 
   virtual void draw() =0;
   virtual ~Figure(){}
protected:
   int size_;
   Direction dir_;
};


class Line: public Figure{
public: 
   Line(int size, Direction dir): Figure(size, dir){}
   Line* clone(){return new Line(size_, dir_);}  
   void draw(){
      for(int i=0; i<size_; ++i){
	 cout << '*';
	 if(dir_ == Direction::Vertical) cout << endl;
      }
      if(dir_ == Direction::Horizontal) cout << endl;
   }
};

class Square: public Figure{
public:
   Square(int size, char fill):fill_(fill),
	 Figure(size, Direction::Horizontal){}
   Square* clone(){return new Square(size_, fill_);}
   void draw(){
      for(int i=0; i<size_; ++i){
	 for(int j=0; j<size_; j++)
	    cout << fill_;
	 cout << endl;
      }
   }
protected:
   char fill_;
};

class Triangle: public Figure{
public:
   Triangle(int size, Direction dir): Figure(size, dir){}
   Triangle* clone(){return new Triangle(size_, dir_);}
   void draw(){
      for(int i=0; i<size_; ++i){
	 for(int j=0; j<size_; j++)
	    if((dir_ == Direction::Vertical   
		        && i <= j) || 
	       (dir_ == Direction::Horizontal 
		        && i >= j))
	       cout << '*';
	    else
	       cout << ' ';
	 cout << endl;
      }
   }
};

// figure registry 
class FigureRegistry {
public:
   static void setup(int size, Direction dir, char fill){
      prototypes_ = {{"line", new Line(size, dir)},
		     {"square", new Square(size, fill)},
		     {"triangle", new Triangle(size, dir)}
                    };
      }
   static Figure *make(std::string type){
      return prototypes_[type]->clone();
   }
private:
   static std::map<std::string,Figure*> prototypes_;
};

std::map<std::string,Figure*> FigureRegistry::prototypes_;


int main(){
   srand(time(nullptr));

   // declares prototype objects
   FigureRegistry::setup(3, Direction::Horizontal, '$');

   std::vector<Figure*> figures;
   const int figNum = 9;

   // allocate a few squares, lines and triangles
   for(int i=0; i<figNum; ++i)
      switch(rand()%3){
      case 0: 
	 figures.push_back(FigureRegistry::make("line")); 
	 break;
      case 1:
	 figures.push_back(FigureRegistry::make("square"));
	 break;
      case 2:
	 figures.push_back(FigureRegistry::make("triangle"));
	 break;
      }

   for(int i=0; i<figNum; ++i){
      figures[i]->draw(); // draw figures
      //      cout << endl;
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
