// pimpl header, using unique_ptr
// Mikhail Nesterenko
// 11/24/2014

#ifndef PIMPL_H
#define PIMPL_H

#include <memory>


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
   std::unique_ptr<Body> b_; // pointer with forward class declaration
};

#endif // PIMPL_H

