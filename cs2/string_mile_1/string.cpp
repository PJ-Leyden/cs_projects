#include "string.hpp"

String::String(){
	str[0] = 0;
}

String::String(char c){
	str[0] = c;
	str[1] = 0;
}

String::String(const char ch[]){
	int indx = 0;
	while(ch[indx] != 0){
		str[indx] = ch[indx];
		++indx;
	}
	str[indx] = 0;
}

int String::capacity() const{
	return STRING_SIZE - 1;
}

int String::length() const{
	int len = 0;
	while(str[len] != 0){
		++len;
	}
	return len;
}

char& String::operator[](int indx){
	return str[indx];
}

char String::operator[](int indx) const{
	return str[indx];
}

String String::operator+(const String &rhs) const{//s3 = s1 + s2, s1 = "Hello", s2 = "World"
	String result(str);

	for(int i = 0; i < rhs.length(); ++i){
		result[length() + i] = rhs[i];
	}

	result[length() + rhs.length()] = 0;

	return result;

}

void String::operator=(const String &rhs){

	for(int i = 0; i < rhs.length(); ++i){
		str[i] = rhs.str[i];
	}

	str[rhs.length()] = 0;

}