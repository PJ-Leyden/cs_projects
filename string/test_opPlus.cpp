////File: test_opPlus.cpp
//Author: P.J. Leyden
//Test: operator+
#include "string.hpp"
#include <iostream>
#include <vector>
#include <cassert>
int main(){

	{
		String str1 = "abcd";
		String str2 = "efgh";
		String str3 = str1 + str2;
		assert(str1 == "abcd");
		assert(str2 == "efgh");
		assert(str3 == "abcdefgh");
	}
		std::cout<<"//======================================================"<<'\n';
	{
		String str1 = " ";
		String str2 = "abcd";
		String str3 = str1 + str2;
		assert(str1 == " ");
		assert(str2 == "abcd");
		assert(str3 == " abcd");
	}
		std::cout<<"//======================================================"<<'\n';
	{
		String str1 = " ";
		String str2 = "abcd";
		String str3 = str2 + str1;
		assert(str1 == " ");
		assert(str2 == "abcd");
		assert(str3 == "abcd ");
	}
		std::cout<<"//======================================================"<<'\n';
	{
		String str1 = "";
		String str2 = "abcd";
		String str3 = str1 + str2;
		assert(str1 == "");
		assert(str2 == "abcd");
		assert(str3 == "abcd");
	}
		std::cout<<"//======================================================"<<'\n';
	{
		String str1 = "abcd";
		String str2 = str1 + str1;
		assert(str1 == "abcd");
		assert(str2 == "abcdabcd");
	}
		std::cout<<"//======================================================"<<'\n';
		
		std::cout<<"Finished Testing operator+"<<'\n';
}