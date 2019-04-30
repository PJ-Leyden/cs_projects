// prototype pattern example, demonstrates 
// covariant type use
// Mikhail Nesterenko
// 2/18/2014

#include <iostream>
#include <vector>
using std::cout; using std::endl;
using std::vector;

// base class
class Figure{
public:
   Figure(int size): size_(size){}
   void resize(int newSize){size_=newSize;}
   // method required for prototype pattern
   virtual Figure* clone() =0; 
   virtual void draw() =0;
   virtual ~Figure(){}
protected:
   int size_;
};


enum class Direction {Horizontal, Vertical};

class Line: public Figure{
public: 
   Line(int size, Direction dir): 
      dir_(dir), Figure(size){}

   /*
   // clone returns base class type
   Figure* clone() override {return new Line(size_, dir_);}  
   */
   
   // clone returns covariant type
   Line* clone() override {return new Line(size_, dir_);}  
   

   // flip changes direction of the line
   // note, only lines can flip, not figures
   void flip(){
      dir_= dir_ == Direction::Horizontal ? 
	            Direction::Vertical: 
	            Direction::Horizontal;
   } 

   void draw(){
      for(int i=0; i<size_; ++i){
	 cout << '*';
	 if(dir_ == Direction::Vertical) cout << endl;
      }
      if(dir_ == Direction::Horizontal) cout << endl;
   }
 protected:
   Direction dir_;
};



int main(){
   // declares prototype line
   Line prototypeLine(4, Direction::Horizontal);
   // vector <Figure*> figures; 
   vector <Line*> figures;

   for(int i=0; i<5; ++i)
      figures.push_back(prototypeLine.clone()); 

   // flip every other one
   for(int i=0; i<5; ++i) {
      // use method available for lines only
      if(i % 2 == 0) 
	 figures[i] -> flip(); 	      
   }
   
   // draw figures
   for(int i=0; i<5; ++i) figures[i]->draw(); 
}
