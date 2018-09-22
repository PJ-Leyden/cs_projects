//File: stack.hpp
//Author: P.J. Leyden
//Date: April 2nd, 2016

//====================================================
template <typename T>
class node{
public:
	T data;
	node<T>* next;
	node():next(0){};
	node(const T& x):data(x), next(0){};
};
//====================================================
//Notes: 
//	ptr -> data == *ptr.data | so, basically
//	this will go to whatever it is ptr POINTS TOO
//	and access the variable in it.
//====================================================
template <typename T>
class Stack{
public:
	Stack():tos(0){
	};

	Stack(Stack<T>&& rhs){//r value move constr
		swap(rhs);
		//Here to collapse
	};

	Stack(const Stack<T>& actual){//copy constr
		node<T>* make = 0;
		node<T>* temp = actual.tos;
		tos = 0;
		while(temp != 0){
			if(tos == 0){
				tos = new node<T>(temp -> data);
				temp = temp -> next;
				make = tos;
			}else{
				make -> next = new node<T>(temp -> data);
				temp = temp -> next;
				make = make -> next;
			}
		}
	};

	~Stack(){//deconstructor
		while(tos != 0){
			node<T>* temp = tos;
			tos = tos -> next;
			delete temp;
		}
	};

	void swap(Stack<T>& rhs){//swaps the tos basically. Or in other words swaps their names
		node<T>* temp = tos;
		tos = rhs.tos;
		rhs.tos = temp;
		temp = 0;
	};

	Stack<T>& operator=(Stack<T>&& rhs){//move assign used for r value
		swap(rhs);
		return *this;
	};

	Stack<T>& operator=(const Stack<T>& rhs){//copy assign
		delete this;
		*this = new Stack<T>(rhs);
		return *this;
	};

	bool isEmpty()const{
		return tos == 0;
		//Here to collapse
	};

	//bool isFull()const{;
	//};

	T pop(){
		node<T>* temp = tos;
		T result = tos -> data;
		tos = tos -> next;
		delete temp;
		return result;
	};

	void push(const T& newData){
		node<T>* temp = new node<T>(newData);
		temp -> next = tos;
		tos = temp;
		temp = 0;//avoid deletion of new data
	};

private:
	node<T>* tos;//tos == top of stack
};
//====================================================
/*
template <typename T>
	Stack<T>::Stack(Stack<T>&& rhs){
		swap(rhs);
		//Here to collapse
	}
template <typename T>
	Stack<T>::Stack(const Stack<T>& actual){
		node<T>* make = 0, temp = actual.tos;
		tos = 0;
		while(temp != 0){
			if(tos == 0){
				tos = new node<T>(temp -> data);
				temp = temp -> next;
				make = tos;
			}else{
				make -> next = new node<T>(temp -> data);
				temp = temp -> next;
				make = make -> next;
			}
		}
	}
template <typename T>
	Stack<T>::~Stack(){
		while(tos != 0){
			node<T>* temp = tos;
			tos = tos -> next;
			delete temp;
		}
	}
template <typename T>
	void Stack<T>::swap(Stack<T>& rhs){
		node<T>* temp = tos;
		tos = rhs.tos;
		rhs.tos = temp;
		temp = 0;
	}
template <typename T>
	void Stack<T>::push(const T& newData){
		node<T>* temp = new node<T>(newData);
		temp -> next = tos;
		tos = temp;
		temp = 0;//avoid deletion of new data
	}
template <typename T>
	T Stack<T>::pop(){
		node<T>* temp = tos;
		T result = tos -> data;
		tos = tos -> next;
		delete temp;
		return result;
	}
template <typename T>
	Stack<T>& operator=(Stack<T> rhs){
		*this.swap(rhs);
		return *this;
	}
template <typename T>
	Stack<T>& operator=(const Stack<T>& rhs){//??????//
		delete this;
		*this = new Stack<T>(rhs);
		return *this;
	}
*/
//====================================================