// vector and list algorithms
// Mikhail Nesterenko
// Modified by: P.J. Leyden
// 3/11/2014

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

// reading a list from a fileName
void readRoster(list<list<string>>&, string);  

// printing a list out
void printRoster(const list<list<string>>&); 

//main function
int main(int argc, char* argv[]){

	if (argc <= 1){ 
		cout << "usage: " << argv[0] 
		<< " list of courses, dropouts last" 
		<< endl; exit(1);
	}

	//vector of students and there courses
	list<list<string>> students; 

	//read in evry file 
	for(int i=1; i < argc - 1; ++i){
		readRoster(students, argv[i]);
	}

	cout << "\nStudents: \n==================================\n";
	printRoster(students);

	//reading in dropouts
	list<list<string>> dropouts; 
	readRoster(dropouts, argv[argc-1]);
	cout << "\n\nDropouts: \n==================================\n"; 
	printRoster(dropouts);

	return 0;
}


void readRoster(list<list<string>>& students, string fileName){

	ifstream course(fileName);
	
	string first, last, course_name;
	course_name = fileName.substr(0, fileName.size() - 4);

	while(course >> first >> last){
		string temp = first + ' ' + last;
		bool found_name = false;
		//iterate through vector
		for(auto &lst : students){
			//if first string matches add onto list
			if(lst.front() == temp){
				lst.push_back(course_name);
				found_name = true;
				break;
			}
		}

		if(!found_name){
			list<string> new_entry;
			new_entry.push_back(temp);
			new_entry.push_back(course_name);
			students.push_back(new_entry);
		}

	}
	course.close();
}

// printing a list out
void printRoster(const list<list<string>>& roster){
	for(const auto& lst : roster){
		for(const auto& str : lst){
			cout << str << " ";
		}
		cout << endl;
	}
}
