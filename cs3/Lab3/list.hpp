// node class tempate used to contruct lists
// Mikhail Nesterenko
// 5/01/00
//Modified: P.J. Leyden
//Date: Jan 29th, 2019

#ifndef LIST_H_
#define LIST_H_

// the pointer part of every list is the same
// lists differ by data part
template <typename T>
class node{
public:
	node(): next_(nullptr) {}

	// functions can be inlined
	T getData()const{
		//
		return data_;
	}

	void setData(const T& data){
		//
		data_ = data;
	}

	node<T>* getNext() const{
		//
		return next_;
	}

	void setNext(node<T> *const next){
		//
		next_ = next;
	}

private:
	T data_;
	node<T> *next_;

};

#endif // LIST_H_

#ifndef COLLECTION_H_
#define COLLECTION_H_

template <typename U>
class Collection{
public:
	Collection(): first_(nullptr), last_(nullptr) {}

	void addItem(U item){

		//if there are no nodes in the collection
		if(first_ == nullptr){
			first_ = new node<U>;
			first_->setData(item);
			last_ = first_;

		//if there are at least 1 or more items in the collection
		}else{
			last_->setNext(new node<U>);
			last_ = last_->getNext();
			last_->setData(item);

		}
	}

	void removeItem(U item){

		if(first_ == nullptr){
			return;
		}

		node<U> *previous = nullptr;
		node<U> *current = first_;

		while(current->getNext() != nullptr){
			//if we find an instance of item
			if(current->getData() == item){
				//if the first object in collection is an instance of item
				if(previous == nullptr){
					first_->setNext(current->getNext());
					delete current;
					current = first_;

				//if there is a previous, meaning we are not at the first node
				}else{
					previous->setNext(current->getNext());
					delete current;
					current = previous->getNext();
				}

			//if we did not find an instance of item
			}else{
				previous = current;
				current = current->getNext();
			}
		}

		//final check of last item
		if(current->getData() == item){
			//if only one item and it is to be removed
			if(current == first_){
				first_ = previous;
			}

			last_ = previous;
			delete current;
		}
	}

	U lastItem(){
		//
		return last_->getData();
	}

	void printCollection(){

		if(first_ == nullptr){
			return;
		}

		node<U> *current = first_;
		//int count = 1;
		while(current->getNext() != nullptr){
			std::cout << current->getData() << " ";
			//++count;
			current = current->getNext();
		}

		//final print of last item
		std::cout << current->getData() << '\n';
	}

	void debugPrint(){

		if(first_ == nullptr){
			return;
		}

		node<U> *current = first_;
		int count = 1;
		while(current->getNext() != nullptr){
			std::cout << count << ") " << current->getData() << " : ";
			if(current->getNext() == nullptr){
				std::cout << "nullptr";
			}else{
				std::cout << "node";
			}
			std::cout << "\n";
			++count;
			current = current->getNext();
		}

		//final print of last item
		std::cout << count << ") " << current->getData() << " : ";
			if(current->getNext() == nullptr){
				std::cout << "nullptr";
			}else{
				std::cout << "node";
			}
			std::cout << "\n";
	}

	friend bool equal(const Collection &lhs, const Collection &rhs){

		//the collection would be equal to itself
		if(&lhs == &rhs){
			return true;
		}

		bool result = true;
		node<U> *lhs_current, *rhs_current;
		lhs_current = lhs.first_;
		rhs_current = rhs.first_;

		while(lhs_current->getNext() != nullptr && rhs_current->getNext() != nullptr){
			if(lhs_current->getData() != rhs_current->getData()){
				result = false;
				break;
			}else{
				lhs_current = lhs_current->getNext();
				rhs_current = rhs_current->getNext();
			}
		}

		//final check (first part checks last nodes data second checks if one collection is longer
		//than the other)
		if(lhs_current->getData() != rhs_current->getData() || lhs_current->getNext() != nullptr || rhs_current->getNext() != nullptr){
			result = false;
		}

		return result;
	}

private:
	node<U> *first_;
	node<U> *last_;
};	

#endif
