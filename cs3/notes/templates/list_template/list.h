// node class tempate used to contruct lists
// Mikhail Nesterenko
// 5/01/00

#ifndef LIST_H_
#define LIST_H_

// the pointer part of every list is the same
// lists differ by data part
template <typename T>
class node{
public:

  node(): next_(nullptr) {}

  // functions can be inlined
  T getData()const{return data_;}
  void setData(const T& data){data_=data;}

  // or can be defined outside
  node<T>* getNext() const;
  void setNext(node<T> *const);

private:
  T data_;
  node<T> *next_;
};

//
// member functions for node
//
template <typename T>
node<T>* node<T>::getNext()const{
  return next_;
}

template<typename T>
void node<T>::setNext(node<T> *const next){
   next_=next;
}

#endif // LIST_H_
