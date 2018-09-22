//string.cpp
//with modified code from Dr. J. Maletic's string.hpp
#include "string.hpp"
#include <iostream>
//=============================================================
String::String(){//default constr
	str[0] = '\0';
	//HC
}
//=============================================================
String::String(char temp1){//single char constr
	str[0] = temp1;
	str[1] = '\0';
}
//=============================================================
String::String(const char temp[]){//char array constr
	int indx = 0;
	while(temp[indx] != '\0'){
		str[indx] = temp[indx];
		indx++;
	}
	str[indx] = '\0';
}
//=============================================================
std::ostream& operator<<(std::ostream& out, const String& temp){//allows for print out of String
	int indx = 0;
	while(temp.str[indx] != '\0'){
		//out<<"Char in String at index "<<indx<<" == "<<temp.str[indx]<<std::endl;
		out<<temp.str[indx];
		indx++;
	}
	return out;
}
//=============================================================
int String::length() const{//gives length of string
	int indx = 0;
	while(str[indx] != '\0'){
		indx++;
	}
	return indx;
}
//=============================================================
int String::capacity() const{//gives capacity
	return DEFAULT_STRING_CAPACITY;
	//HC
}
//=============================================================
char String::operator[](int indx) const{//returns copy of char at indx
	char result = str[indx];
	return result;
}
//=============================================================
char& String::operator[](int indx){//allows for reassignment of char at indx
	char &chr = str[indx];
	return chr;
}
//=============================================================
bool String::operator==(const String& rhs) const{//comparison operator
	bool result = false;
	int len = length();
	if(len != rhs.length()){
		return result;
	}
	for(int i = 0; i < len; i++){
		if(str[i] != rhs.str[i]){
			return result;
		}
	}
	result = true;
	return result;
}
//=============================================================
bool String::operator<(const String& rhs) const{//less than operator
	int indx = 0;
	bool result = true;
	while((str[indx] != '\0') && (rhs.str[indx] != '\0')){
		if(str[indx] == rhs.str[indx]){
			indx++;
		}
		else if(str[indx] < rhs.str[indx])
		{
			return result;
			
		}
		else if(str[indx] > rhs.str[indx]){
			result = false;
			return result;
		}
	}
	//if it gets out of the first loop it was equal with only a possiblity of varying lengths
	if(length() < rhs.length()){
		return result;
	}
	else{
		result = false;
		return result;
	}
}
//=============================================================
String String::operator+(const String& rhs) const{
	int size = length() + rhs.length();
	char temp[size];
	for(int i = 0; i < length(); i++){
		temp[i] = str[i];
		//std::cerr<<"Char at "<<i<<" is == "<<temp[i]<<std::endl;
	}
	for(int i = length(); i < size; i++){
		temp[i] = rhs.str[i - rhs.length()];
		//std::cerr<<"Char at "<<i<<" is == "<<temp[i]<<std::endl;
	}
	String result(temp);
	//std::cerr<<result.length()<<std::endl;
	return result;
}
//=============================================================
std::istream& operator>>(std::istream& in, String& inString){
	char tempString[256];
	int length = 0;
	while(true){//find length
		char findLength;
		in >> findLength;
		tempString[length] = findLength;
		if(findLength == ';'){
			break;
		}
		length++;
	}
	//=====================================
	for(int i = 0; i < length; i++){
		inString.str[i] = tempString[i];
	}
	return in;
}
//=============================================================
String operator+(const char lhs[], const String& rhs){
	String temp(lhs);
	String result = temp + rhs;
	return result;
}
//=============================================================
String operator+(char lhs, const String& rhs){
	String temp(lhs);
	String result = temp + rhs;
	return result;
}
//=============================================================
bool operator==(const char lhs[], const String& rhs){
	bool result;
	String temp(lhs);
	result = (temp == rhs);
	return result;
}
//=============================================================
bool operator==(char lhs, const String& rhs){
	bool result;
	String temp(lhs);
	result = (temp == rhs);
	return result;
}
//=============================================================
bool operator<(const char lhs[], const String& rhs){
	bool result;
	String temp(lhs);
	result = (temp < rhs);
	return result;
}
//=============================================================
bool operator<(char lhs, const String& rhs){
	bool result; 
	String temp(lhs);
	result = (temp < rhs);
	return result;
}
//=============================================================
bool operator<=(const String& lhs, const String& rhs){
	bool result;
	if(lhs < rhs){
		result = true;
	}
	else if(lhs == rhs){
		result = true;
	}
	else{
		result = false;
	}
	return result;
}
//=============================================================
bool operator!=(const String& lhs, const String& rhs){
	bool result;
	if(lhs == rhs){
		result = false;
	}
	else{
		result = true;
	}
	return result;
}
//=============================================================
bool operator>=(const String& lhs, const String& rhs){
	bool result;
	if(lhs < rhs){
		result = false;
	}
	else{
		result = true;
	}
	return result;
}
//=============================================================
bool operator>(const String& lhs, const String& rhs){
	bool result;
	if(lhs <= rhs){
		result = false;
	}
	else{
		result = true;
	}
	return result;
}
//=============================================================
String String::substr(int pos, int length) const{
	String result;
	for(int i = pos; i < pos + length; i++){
		result.str[i - pos] = str[i];
	}
	return result;
}
//=============================================================
int String::findstr(const String& toFind) const{
	int result = -1;
	int searchLen = length();
	char strt = toFind[0];
	for(int i = 0; i < searchLen; i++){//starts iteration through pile(pile = string looking through)
		if(str[i] == strt){//if it finds the first letter
			result = i;
			for(int j = 1; j < toFind.length(); j++){//loops through to find the string. verify basically
				if(str[j] != toFind.str[j]){
					result = -1;
					break;//1
				}
				else if(j == toFind.length() - 1){
					return result;
				}
			}
			//break 1 goes here
		}
	}
	return result;
}
//=============================================================
int String::findchar(char toFind) const{
	int result = -1;
	for(int i = 0; i < length(); i++){
		if(str[i] == toFind){
			result = i;
			return result;
		}
	}
	return result;
}