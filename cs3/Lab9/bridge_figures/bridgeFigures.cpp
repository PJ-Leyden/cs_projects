// filled/hollow figures demonstrates Bridge Design Pattern,
// square is either hollow or square and is painted with a particular character,
// it is bridged over Figure --> Fill abstract body/handle
// Mikhail Nesterenko
// 2/12/2014

#include <iostream>

using std::cout; using std::endl; using std::cin;

// abstract body
class Fill{
public:
   Fill(char bc, char ic):fillBorder_(bc), fillInternal_(ic){}
   virtual char getBorder()=0;
   virtual char getInternal()=0;
   virtual ~Fill() {}
protected:
   char fillBorder_;
   char fillInternal_;
};

// concrete body
class Hollow: public Fill{
public:
   Hollow(char bc):Fill(bc, ' '){}
   char getBorder() override {return fillBorder_;}
   char getInternal() override {return fillInternal_;}
   ~Hollow(){}
};



// another concrete body
class Filled: public Fill {
public:
   Filled(char fillChar):Fill(fillChar, fillChar){}
   char getBorder() override {return fillBorder_;}
   char getInternal() override {return fillInternal_;}
   ~Filled(){}
};

class EnhancedFill: public Fill {
public:
   EnhancedFill(char fb, char fi):Fill(fb, fi){}
   char getBorder() override {return fillBorder_;}
   char getInternal() override {return fillInternal_;}
};

// abstract handle
class Figure {
public:
   Figure(int size, Fill* fill): size_(size), 
				 fill_(fill){}
   virtual void draw() =0;
   void changeFill(Fill*);

   virtual ~Figure(){}
protected:
   int size_;
   Fill *fill_;
};

void Figure::changeFill(Fill *f){
	if(fill_ != nullptr){delete fill_;}
	fill_ = f;
}

// concrete handle
class Square: public Figure{
public:
   Square(int size, Fill* fill): Figure(size, fill){}
   void draw() override;

};


void Square::draw(){
   for(int i=0; i < size_; ++i){
      for(int j=0; j < size_; ++j)
	 if(i==0 || j==0 || i==size_-1 || j==size_-1 )
	    cout << fill_ -> getBorder();
	 else
	    cout << fill_ -> getInternal();
      cout << endl;
   }
}


int main(){
   
   Fill* hollowPaintY = new Hollow('Y');
   Fill* filledPaintStar = new Filled('*');

   
   Figure *smallBox = new Square(4, filledPaintStar);
   Figure *bigBox = new Square(10, hollowPaintY);

   smallBox->draw();
   cout << endl;
   bigBox -> draw();
   
   
   // ask user for figure parameters
   cout << "Enter fill character: "; 
            char fchar; cin >> fchar;
   cout << "Filled or hollow? [f/h] "; 
           char ifFilled; cin >> ifFilled;
   cout << "Enter size: "; int size; cin >> size;
  
   
   Figure *userBox = new Square(size, ifFilled == 'f'? 
	       static_cast<Fill *>(new Filled(fchar)):
	       static_cast<Fill *>(new Hollow(fchar))
     				                     ); 
   userBox -> draw();
   cout << endl;
   
   delete userBox;
   userBox = new Square(size, static_cast<Fill *>(new EnhancedFill(fchar, 'g')));
   userBox -> draw();
   cout << endl;

   return 0;
}
