//====================================================================
//File: string.cpp
//
//Version: 1.0
//Date: March 4th, 2016
//Author: P.J. Leyden
//====================================================================
//Class Invariant: 
//              1.) char* temp can't have greater length than capacity
//====================================================================
//General Notes:
//              1.) The pointer can use brakets because they are designed to. We have to 
//                  overwrite the brakects so the name of the string can use them
//              2.) Pointers are basically arrays with no methods or class for the matter
//              3.)
//====================================================================
#include "string.hpp"
#include <iostream>
//====================================================================
String::String(){//default constr
	s = new char[DEFAULT_STRING_CAPACITY];
	s[0] = '\0';
	Capacity = DEFAULT_STRING_CAPACITY;
}
//====================================================================
String::String(char temp):String(){//constr - conversion of a single character to a string
	s[0] = temp;
	s[1] = '\0';
}
//====================================================================
String::String(const char* temp){//constr - conversion of litterally char array to string
	s = new char[DEFAULT_STRING_CAPACITY];
	Capacity = DEFAULT_STRING_CAPACITY;
	int indx = 0;
	while(temp[indx] != '\0'){
		s[indx] = temp[indx];
		indx++;
	}
	s[indx] = '\0';
}
//====================================================================
String::String(int initCap, const char* temp){//constr - set cap and init value. Ideally, the capacity should be 
	int indx = 0;                             //         long enough for the litteral and the null terminator
	Capacity = initCap;                         
	s = new char[Capacity];
	while(temp[indx] != '\0' && !(indx >= initCap)){//checks for null terminator and that the indx 
		s[indx] = temp[indx];                       //is not greater than or equall to the capacity  
		indx++;
	}
	if(indx >= initCap){
		std::cerr<<"Character litteral length greater than given capacity"<<std::endl;
	}
	else{
		s[indx] = '\0';
	}
}
//====================================================================
String::String(int initCap){//constr - sets empty string with init cap
	Capacity = initCap;
	s = new char[Capacity];
	s[0] = '\0';
}
//====================================================================
String::String(const String& temp){//copy constr - copies... duh...
	int indx = 0;
	Capacity = temp.Capacity;
	s = new char[Capacity];
	while(temp.s[indx] != '\0'){
		s[indx] = temp.s[indx];
		indx++;
	}
	s[indx] = '\0';
}
//====================================================================
String::~String(){//destructor - destructs... duh...
	delete[] s;
	//HC
}
//====================================================================
String& String::operator=(String temp){// = op with copy symantex
	delete[] s;
	Capacity = temp.Capacity;
	s = new char[Capacity];
	int indx = 0;
	while(temp.s[indx] != '\0'){
		s[indx] = temp.s[indx];
		indx++;
	}
	s[indx] = '\0';
	return *this;
}
//====================================================================
void String::swap(String& rhs){
	String temp(*this);
	*this = rhs;
	rhs = temp;
	//delete temp;
}
//====================================================================
void String::resetCapacity(int newCap){
	String temp(*this);
	Capacity = newCap;
	delete[] s;
	s = new char[Capacity];
	int indx = 0;
	while(temp.s[indx] != '\0'){
		s[indx] = temp.s[indx];
		indx++;
	}
	s[indx] = '\0';
	//delete temp;
}
//====================================================================
char& String::operator[](int indxAt){
	char &result = s[indxAt];
	return result;
}
//====================================================================
char String::operator[](int indxAt) const{
	char result = s[indxAt];
	return result;
}
//====================================================================
int String::capacity() const{
	return Capacity;
	//HC
}
//====================================================================
int String::length() const{
	int result = 0;
	while(s[result] != '\0'){
		result++;
	}
	return result;
}
//====================================================================
bool String::operator==(const String& rhs) const{
	if(length() != rhs.length()){
		return false;;
	}
	int indx = 0;
	while(s[indx] != '\0' && rhs[indx] != '\0'){
		if(s[indx] != rhs[indx]){
			return false;
		}
		else{
			indx++;
		}
	}
	if(Capacity == rhs.capacity()){
		return true;
	}
	else{
		return false;
	}
}
//===================================================================
bool String::operator<(const String& rhs) const{
	int indx = 0;
	if(*this == rhs){
		return false;
	}
	while((s[indx] != '\0') && (rhs[indx] != '\0')){
		if(s[indx] == rhs[indx]){
			indx++;
		}
		else if(s[indx] < rhs[indx])
		{
			return true;
			
		}
		else if(s[indx] > rhs[indx]){
			return false;
		}
	}
	//std::cerr<<"Less Than Problem"<<std::endl;
	if(length() < rhs.length()){
		return true;
	}
	return false;//here to catch issue
}
//===================================================================
String String::operator+(const String& rhs) const{
	int size = length() + rhs.length() + 1;
	char temp[size];
	for(int i = 0; i < length(); i++){
		temp[i] = s[i];
		//std::cerr<<"Char at "<<i<<" is == "<<temp[i]<<std::endl;
	}
	for(int i = length(); i < size - 1; i++){
		temp[i] = rhs.s[i - rhs.length()];
		//std::cerr<<"Char at "<<i<<" is == "<<temp[i]<<std::endl;
	}
	temp[size - 1] = '\0';
	String result(temp);
	//std::cerr<<result.length()<<std::endl;
	return result;
}
//===================================================================
std::ostream& operator<<(std::ostream& out, const String& temp){//allows for print out of String
	int indx = 0;
	while(temp[indx] != '\0'){
		//out<<"Char in String at index "<<indx<<" == "<<temp.str[indx]<<std::endl;
		out<<temp.s[indx];
		indx++;
	}
	return out;
}
//==================================================================
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
		inString[i] = tempString[i];
	}
	return in;
}
//==================================================================
String operator+(const char lhs[], const String& rhs){
	String temp(lhs);
	String result = temp + rhs;
	return result;
}
//==================================================================
String operator+(char lhs, const String& rhs){
	String temp(lhs);
	String result = temp + rhs;
	return result;
}
//==================================================================
bool operator==(const char lhs[], const String& rhs){
	bool result;
	String temp(lhs);
	result = (temp == rhs);
	return result;
}
//==================================================================
bool operator==(char lhs, const String& rhs){
	bool result;
	String temp(lhs);
	result = (temp == rhs);
	return result;
}
//==================================================================
bool operator<(const char lhs[], const String& rhs){
	bool result;
	String temp(lhs);
	result = (temp < rhs);
	return result;
}
//==================================================================
bool operator<(char lhs, const String& rhs){
	bool result; 
	String temp(lhs);
	result = (temp < rhs);
	return result;
}
//==================================================================
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
//==================================================================
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
//==================================================================
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
//==================================================================
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
//==================================================================
String String::substr(int pos, int length) const{
	String result;
	for(int i = pos; i < pos + length; i++){
		result[i - pos] = s[i];
	}
	result[length] = '\0';
	return result;
}
//==================================================================
int String::findstr(const String& toFind) const{
	int result = -1;
	char strt = toFind[0];
	for(int i = 0; i < length(); i++){//starts iteration through pile(pile = string looking through)

		if(s[i] == strt){//if it finds the first letter

			result = i;
			//=========================================FOR
			for(int j = 0; j < toFind.length(); j++){//loops through to find the string. verify basically

				if(s[i + j] != toFind.s[j]){
					result = -1;
					break;//1
				}
				else if(j == toFind.length() - 1){
					return result;
				}

			}
			//=========================================END FOR
			//break 1 goes here
		}
	}
	return result;
}
//==================================================================
int String::findchar(char toFind) const{
	int result = -1;
	for(int i = 0; i < length(); i++){
		if(s[i] == toFind){
			result = i;
			return result;
		}
	}
	return result;
}
//==================================================================