//object_construction.cpp
#include <iostream>
/*#ifndef Obj_Maker
#define Obj_Maker
#include <iostream>

class obj_maker{
public:
	obj_maker();
	obj_maker(const obj_maker&);
	~obj_maker();
	obj_maker operator=(const obj_maker);

private:
	int *ptr = NULL;
};
#endif*/

class obj_maker{
public: 
	obj_maker(){
		std::cout<<"Default Constructor"<<std::endl;
	}
	obj_maker(const obj_maker& temp){
		std::cout<<"Copy Constructor"<<std::endl;
	}
	~obj_maker(){
		std::cout<<"Destructor"<<std::endl;
	}
	obj_maker operator=(const obj_maker& temp){
		std::cout<<"Assign"<<std::endl;
		return temp;
	}

private:
	int *ptr = NULL;
};

int main() {
	obj_maker obj1;
	obj_maker obj1_copy(obj1);
	obj_maker obj2;
	obj2 = obj1;
	obj_maker *ptr1 = new obj_maker(); 

	delete ptr1;

	return 0;
}
