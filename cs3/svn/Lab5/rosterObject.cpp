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
#include <map>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;
using std::map;
using std::pair;


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

private:
	string firstName_;
	string lastName_;
};




// reading a list from a fileName
void readRoster(map<Student, list<string>>&, string);  
// printing a list out
void printRoster(const map<Student, list<string>>&); 

int main(int argc, char* argv[]){

	if (argc <= 1){ 
		cout << "usage: " << argv[0] << " list of courses, dropouts last" << endl; 
		exit(1);
	}

	// vector of courses of students
	map<Student, list<string>> students; 

	for(int i=1; i < argc; ++i){
		readRoster(students, argv[i]);
		cout << "Read: " << argv[i] << endl;
	}

	printRoster(students);

	return 0;
}


void readRoster(map<Student, list<string>>& roster, string fileName){
	ifstream course(fileName);
	
	string first, last, course_name = fileName.substr(0, fileName.size() - 4);
	while(course >> first >> last){
	  auto it = roster.find(Student(first, last));
	  if(it == roster.end()){
	    roster.insert( pair< Student, list<string> >  (Student(first, last), list<string>({course_name}))  );
	  }else{
	    (it->second).push_back(course_name);
	  }
	}
	course.close();
}

// printing a list out
void printRoster(const map<Student, list<string>>& roster){
  for(auto it = roster.cbegin(); it != roster.cend(); ++it){
    cout << (it->first).get_name() << " ";
    for(string c : it->second){
      cout << c << " ";  
    }
    cout << '\n';
  }
}
