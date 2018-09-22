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
#include "logentry.hpp"
#include <iostream>
#include <vector>
//====================================================================
String::String(){//default constr
	s = new char[DEFAULT_STRING_CAPACITY];
	s[0] = '\0';
	Capacity = DEFAULT_STRING_CAPACITY;
}
//====================================================================
String::String(char temp){//constr - conversion of a single character to a string
	s = new char[DEFAULT_STRING_CAPACITY];
	s[0] = temp;
	s[1] = '\0';
	Capacity = DEFAULT_STRING_CAPACITY;
}
//====================================================================
String::String(const char* temp){//constr - conversion of litterally char array to string
	int check = 0;
	while(temp[check] != '\0'){
		check++;
	}
	check++;//accounts for '\0' to be added
	//====================================
	if(check >= 256){
		s = new char[check];
		Capacity = check;
	}
	else{
		s = new char[DEFAULT_STRING_CAPACITY];
		Capacity = DEFAULT_STRING_CAPACITY;
	}
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
		std::cout<<"Character litteral length greater than given capacity"<<std::endl;
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
	//if(*this == temp){
		//return *this;
	//}
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
	/*if(temp.length() >= newCap){
		std::cout<<"Capacity to small"<<'\n';
		Capacity = temp.length() + 1;
	}*/
	//else{
	Capacity = newCap;
	//}
	delete[] s;
	s = new char[Capacity];
	int indx = 0;
	while(temp[indx] != '\0' && indx < Capacity - 1){
		s[indx] = temp[indx];
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
		//std::cerr<<"Failed at length not equal"<<'\n';
		return false;
	}
	int indx = 0;
	while(s[indx] != '\0' && rhs[indx] != '\0'){
		if(s[indx] != rhs[indx]){	
			//std::cout<<"Failed at actual content"<<'\n';		
			return false;
		}
		else{
			indx++;
		}
	}
	//if(capacity() == rhs.capacity()){
		return true;
	//}
	//else{
		//return false;
	//}
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
	}
	for(int i = length(); i < size - 1; i++){
		temp[i] = rhs.s[i - length()];
	}
	temp[size - 1] = '\0';
	String result(temp);
	return result;
}
//===================================================================
std::ostream& operator<<(std::ostream& out, const String& temp){//allows for print out of String
	int indx = 0;
	while(temp[indx] != '\0'){
		//out<<"Char in String at index "<<indx<<" == "<<temp[indx]<<std::endl;
		out<<temp.s[indx];
		indx++;
	}
	return out;
}
//==================================================================
std::istream& operator>>(std::istream& in, String& inString){// in >> inString
	/*{
		//char tempString[256];
		std::vector<char> tempString;
		int length = 0;
		while(true){//find length
			char findLength;
			in >> findLength;
			tempString.push_back(findLength);
			if(findLength == '\0'){
				break;
			}
			length++;
		}
		//=====================================
		if(length >= inString.capacity()){
			inString.resetCapacity(length + 1);
		}
		//=====================================
		for(int i = 0; i < length; i++){
			inString[i] = tempString[i];
		}
		return in;
	}*/
	inString = "";
	char letter;
	if(!(in >> letter)){
		return in;
	}

	inString = inString + letter;
	//std::cerr<<"Bef While\n";
	while(in.get(letter) && letter != ' ' && letter != '\n' && letter != '\t'){
		//std::cerr<<"In While\n";
		//std::cerr<<inString.length()<<"x"<<inString.capacity()<<"\n";
		inString = inString + letter;
		//std::cerr<<inString<<"\n";
	}
	//std::cerr<<"Leave Input\n";
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
std::vector<String> String::split(char deli) const{
	std::vector<String> pieces;
	int indx = 0;
	while(s[indx] != '\0'){
		String temp = "";
		while(s[indx] != deli && s[indx] != '\0'){
			temp = temp + s[indx];
			indx++;
		}
		pieces.push_back(temp);
		if(s[indx] != '\0'){++indx;}
	}
	return pieces;
}
//==================================================================
int String::toInt() const{
	int result = 0;
	for(int indx = 0; indx < length(); indx++){
		int tempNum = 0;
		tempNum = (int)s[indx] - 48;
		int multi = 1;
		for(int i = 0; i < length() - 1 - indx; i++){
			multi = multi * 10;
		}
		tempNum = tempNum * multi;
		result += tempNum;
	}
	return result;
}
//==================================================================
std::vector<LogEntry> parse(std::istream& in) {
	std::vector<String> result;
	String line = "";
	while(!in.eof()){
		line = "";
		char temp;

		bool foundSemi = false;
		while(in.get(temp) && temp != '\n' && !in.eof()){
			if(temp == ';'){
				line = line + temp;
				foundSemi = true;
				continue;
			}
			if(foundSemi){continue;}
			line = line + temp;
		}
		result.push_back(line);
	}
	return result;
}