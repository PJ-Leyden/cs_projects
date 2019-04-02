// figures: class adapter pattern
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

// adaptee/implementer
class LegacyRectangle{
public:
   LegacyRectangle(int topLeftX, 
		   int topLeftY, 
		   int bottomRightX, 
		   int bottomRightY): 
      topLeftX_(topLeftX), 
      topLeftY_(topLeftY), 
      bottomRightX_(bottomRightX), 
      bottomRightY_(bottomRightY){}

   void move(int top_left_x, int top_left_y, int bottom_right_x, int bottom_right_y){
      topLeftX_ = top_left_x;
      topLeftY_ = top_left_y;
      bottomRightX_ = bottom_right_x;
      bottomRightY_ = bottom_right_y;
      oldDraw();
   }
    int getTopLeftX(){ return topLeftX_; }
    int getTopLeftY(){ return topLeftY_; }
    int getBottomRightX(){ return bottomRightX_; }
    int getBottomRightY(){ return bottomRightY_;}

   void oldDraw(){
      for(int i=0; i < bottomRightY_; ++i){
	      for(int j=0; j < bottomRightX_; ++j){
	         if(i >= topLeftY_  && j >= topLeftX_ ){
	            cout << '*';
            }
	         else{
	            cout << ' ';
            }
         }
	      cout << endl;
      }
   }
private: // defining top/left and bottom/right coordinates 
   int topLeftX_;
   int topLeftY_;
   int bottomRightX_;
   int bottomRightY_;
};

// adapter uses multiple inheritance to inherit
// interface and implementation
class SquareAdapter: public Figure, 
		     private LegacyRectangle {
public:
   SquareAdapter(int size): 
         LegacyRectangle(0,0,size,size){};

   void draw() override {
      oldDraw();
   }

   int size(){ return getBottomRightX() - getTopLeftX(); }
   void resize(int newSize){
      move(getTopLeftX(), getTopLeftY(), getTopLeftX() + newSize, getTopLeftY() + newSize);
   }
};


int main(){
   cout << "Init size: ";
   int s = 0;
   std::cin >> s;
   cout << '\n';
   SquareAdapter *square = new SquareAdapter(s);
   square->draw();

   cout << "New size: ";
   std::cin >> s;
   cout << '\n';
   square->resize(s);

}
