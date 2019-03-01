#include "string.hpp"
#include <iostream>

void print(const String &s){
	for(int i = 0; i < s.length(); ++i){
		std::cout << s[i];
	}
}

int main(){

	String s1("Hello");
	String s2(" World");

	std::cout << "String s1: ";
	print(s1);
	std::cout << std::endl;

	std::cout << "String s2: ";
	print(s2);
	std::cout << std::endl;

	String s3 = s1;

	std::cout << "String s3: ";
	print(s3);
	std::cout << std::endl;

	String s4 = s1 + s2;

	std::cout << "String s4: ";
	print(s4);
	std::cout << std::endl;

	return 0;
}