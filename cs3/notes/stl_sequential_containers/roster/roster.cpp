// vector and list algorithms
// Mikhail Nesterenko
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
void readRoster(list<string>& roster, string fileName);  

// printing a list out
void printRoster(const list<string>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ 
      cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" 
      << endl; exit(1);
   }

   // vector of courses of students
   vector <list<string>> courseStudents; 

   for(int i=1; i < argc-1; ++i){
      list<string> roster;
      readRoster(roster, argv[i]);  
      cout << "\n\n" << argv[i] << "\n";  
      printRoster(roster);

      courseStudents.push_back(move(roster)); 
   }

   // reading in dropouts
   list<string> dropouts; 
   readRoster(dropouts, argv[argc-1]); 
   cout << "\n\n dropouts \n"; printRoster(dropouts);

   // master list of students
   list<string> allStudents;  
 
   for(auto& lst : courseStudents) 
     allStudents.splice(allStudents.end(),
			lst);

   cout << "\n\n all students unsorted \n"; 
           printRoster(allStudents);

   // sorting master list
   allStudents.sort();
   cout << "\n\n all students sorted \n"; 
   printRoster(allStudents);

   // eliminating duplicates
   allStudents.unique(); 
   cout << "\n\n all students, duplicates removed \n"; 
   printRoster(allStudents);

   // removing individual dropouts
   for (const auto& str : dropouts)  
      allStudents.remove(str);

   cout << "\n\n all students, dropouts removed \n"; 
   printRoster(allStudents);
}


void readRoster(list<string>& roster, string fileName){
   //   ifstream course(fileName.c_str());
   ifstream course(fileName); // I am trying it
    
   string first, last;
   while(course >> first >> last)
      roster.push_back(
		 move(first + ' ' + last));
   course.close();
}

// printing a list out
void printRoster(const list<string>& roster){
   for(const auto& str : roster)
      cout << str << endl;

}
