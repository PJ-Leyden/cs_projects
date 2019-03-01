// vector and list algorithms with objects in containers
// Mikhail Nesterenko
// Modified by: P.J. Leyden
// 9/10/2018

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;


class Student{
public:
	Student(string firstName, string lastName): 
		firstName_(firstName), lastName_(lastName) 
	{}
 
   // move constructor, not really needed, generated automatically
	Student(Student && org):
		firstName_(move(org.firstName_)),
		lastName_(move(org.lastName_))
	{}
  
	// force generation of default copy constructor
	Student(const Student & org) = default;

	string get_name() const {
		return firstName_ + " " + lastName_;
	}

	void add_course(string course_name){
		classes_.push_back(course_name);
	}

	// needed for unique() and for remove()
	friend bool operator== (Student left, Student right){
		return left.lastName_ == right.lastName_ && left.firstName_ == right.firstName_;
		//here
	}

   // needed for sort()
	friend bool operator< (Student left, Student right){
		  return left.lastName_ < right.lastName_ ||
			(left.lastName_ == right.lastName_ && 
			left.firstName_ < right.firstName_);
	}

	void print() const {
		cout << get_name() << " ";
		for(auto& c : classes_){
			cout << c << " ";
		}
		cout << endl;
	}

private:
	string firstName_;
	string lastName_;
	list<string> classes_;
};




// reading a list from a fileName
void readRoster(list<Student>& roster, string fileName);  
// printing a list out
void printRoster(const list<Student>& roster); 

int main(int argc, char* argv[]){

	if (argc <= 1){ 
		cout << "usage: " << argv[0] << " list of courses, dropouts last" << endl; 
		exit(1);
	}

	// vector of courses of students
	list<Student> students; 

	for(int i=1; i < argc; ++i){
		readRoster(students, argv[i]);
		cout << "Read: " << argv[i] << endl;
	}

	printRoster(students);

	return 0;
}


void readRoster(list<Student>& roster, string fileName){
	ifstream course(fileName);
	
	string first, last, course_name = fileName.substr(0, fileName.size() - 4);
	while(course >> first >> last){
		bool found_student = false;
		for(auto& student : roster){
			if(student.get_name() == first + " " + last){
				found_student = true;
				//add course name to students list
				student.add_course(course_name);
			}
		}

		if(!found_student){
			Student new_student(first, last);
			new_student.add_course(course_name);
			roster.push_back(new_student);
		}
	}
	course.close();
}

// printing a list out
void printRoster(const list<Student>& roster){
	for(const Student& student : roster){
		student.print();
	}
}
