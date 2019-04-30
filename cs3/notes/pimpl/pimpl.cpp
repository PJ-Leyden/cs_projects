// pimpl idiom: defines body and handle method definitions
// Mikhail Nesterenko
// 11/24/2014

#include "pimpl.h"

class Handle::Body{
public:
   Body(int data):data_(data){};
   int getData() const {return data_;}
   void setData(int data){data_=data;}
private:
   int data_;
};

// handle function definitions

Handle::Handle():b_(new Body(0)){}

Handle::Handle(const Handle& org): 
   b_(new Body((org.b_)->getData())){}

Handle& Handle::operator=(const Handle &rhs){
   if(this != &rhs) 
      b_->setData((rhs.b_)->getData());
   return *this;
}

Handle::~Handle(){delete b_;}

int Handle::getData() const {return b_->getData();}
void Handle::setData(int data){b_->setData(data);}
