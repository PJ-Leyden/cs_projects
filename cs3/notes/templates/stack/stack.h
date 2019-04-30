// templated stack implementation
// demonstrates non-type parameter use
// Mikhail Nesterenko
// 2/25/2014

#ifndef STACK_H_
#define STACK_H_

template<typename T=int, int Size=100>
class Stack {
public:
    Stack():top_(-1){}
    void push(T);
    T pop();
    bool full() const;
    bool empty() const;
private:
    T items_[Size];
    int top_;
};


template<typename T, int Size>
void Stack<T,Size>::push(T i){  
   if(top_ < Size-1) items_[++top_] = i;
}

template<typename T, int Size>
T Stack<T,Size>::pop(){
   if(top_ >= 0) return items_[top_--]; 
}

template<typename T, int Size>
bool Stack<T,Size>::full() const{  
   return top_ + 1 == Size; 
}

template<typename T, int Size >
bool Stack<T,Size>::empty() const{  
   return top_ == -1; 
}

#endif // STACK_H_
