#include <iostream>
#include <list>

int main(){
	std::list<std::string> mySentence;
	
	mySentence.push_back("I");
	mySentence.push_back("C++");
	std::list<std::string>::iterator it = mySentence.begin();
	mySentence.insert(++it, "Love");
	mySentence.insert(++it, "Some");

	for(std::list<std::string>::iterator i = mySentence.begin(); i != mySentence.end(); ++i){
		std::cout << *i;
	}
	std::cout << '\n';

	return 0;
}