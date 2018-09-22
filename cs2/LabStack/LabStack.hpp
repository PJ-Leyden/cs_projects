//Name: P.J. Leyden
//File: LabStack.cpp
//Date: March 29th, 2016

#include <iostream>

template <typename T>
class node{
public:
	T data;
	node<T>* next;
	node():next(0){};
	node(const T& x):data(x), next(0){};
};
//=========================================
template <typename T>
class Stack{
public:
	Stack():tos(0){};//init a default Stack with top of stack(tos) pointing at 0
	Stack(Stack<T>&& rhs):Stack(){swap(rhs);};
	Stack(const Stack<T>&);
	~Stack(){
		while(tos -> next != 0){
			node<T>* temp = tos;
			std::cout<<"Here"<<'\n';
			tos = tos -> next;
			delete temp;
		}
		delete tos;
		std::cout<<"Finished"<<'\n';
	};//deconstructor
	void swap(Stack<T>&);
	Stack<T>& operator=(Stack<T>);
	bool isEmpty()const{return tos == 0;};//returns true if tos points to zero, meaning empty
	bool isFull()const;//returns true if full
	T pop(){
		assert(!isEmpty());
		node<T>* temp = tos;
		tos = tos -> next;
		return temp -> data;
	};
	void push(const T& newData){
		//assert(!isFull())
		node<T> temp(newData);
		temp.next = tos;
		tos = &temp;
	};
private:
	node<T>* tos;
};
//=========================================
/*template <typename T>
Stack<T>::Stack(Stack<T>&& rhs):Stack(){
	swap(rhs);
}*/
/*Stack<T>::Stack(const Stack<T>& temp){

}*/
/*~Stack<T>(){

}*/
