//test_part4.cpp
#include "string.hpp"
#include "logentry.hpp"

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <vector>

int main(){
	{
		String str = "1234";
		int myNum = str.toInt();
		std::cout<<myNum<<'\n';
	}
	{
		String str = "0";
		int myNum = str.toInt();
		std::cout<<myNum<<'\n';
	}
	{
		String str = "52";
		int myNum = str.toInt();
		std::cout<<myNum<<'\n';
	}
	{//here
		String str = "00000";
		int myNum = str.toInt();
		std::cout<<myNum<<'\n';
	}
	return 0;
}