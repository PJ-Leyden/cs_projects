// figures: object adapter pattern
// Mikhail Nesterenko
// 2/16/2014

#include <iostream>

using std::cout; using std::endl;

// base interface
class Figure {
public:
   virtual void draw()=0;
   virtual ~Figure(){}
};

// implementer/adaptee
class LegacyRectangle{
public:
   LegacyRectangle(int topLeftX, int topLeftY, 
		   int bottomRightX, int bottomRightY): 
      topLeftX_(topLeftX), 
      topLeftY_(topLeftY), 
      bottomRightX_(bottomRightX), 
      bottomRightY_(bottomRightY){}

   void oldDraw(){
      for(int i=0; i < bottomRightY_; ++i){
         for(int j=0; j < bottomRightX_; ++j)
            if( i >= topLeftY_ && j>= topLeftX_ )
               cout << '*';
            else
               cout << ' ';
         cout << endl;
      }
   }
private: // defining top/left and bottom/right coordinates 
   int topLeftX_;
   int topLeftY_;
   int bottomRightX_;
   int bottomRightY_;
};

// adapter uses composition to delegate requests to adaptee
class SquareAdapter: public Figure{
public:
   SquareAdapter(int size){
      adaptee_= new LegacyRectangle(0,0,size,size);
   }
   void draw() override {
      adaptee_->oldDraw();
   }
private:
   LegacyRectangle *adaptee_;
};


int main(){
   /*
   Figure *square = new SquareAdapter(10);
   square->draw();
   */
   
   SquareAdapter sa(15);
   sa.draw();
}

