// pimpl header, handle class defined
// Mikhail Nesterenko
// 11/24/2014

#ifndef PIMPL_H
#define PIMPL_H

class Handle {
public:
   // default constructor plus big three
   Handle();
   Handle(const Handle&);
   Handle& operator=(const Handle&);
   ~Handle();

   // payload functions
   int getData() const;
   void setData(int);

private:
   class Body; // forward declaration of inner class 
   Body *b_; // pointer with forward class declaration
};

#endif // PIMPL_H

