//File: test_split.cpp
//Author: P.J. Leyden
//Test: split

#include "string.hpp"
#include <iostream>
#include <vector>
#include <cassert>

int main(){
	{
		String str = "abc de fgh";
		
		std::vector<String> test = str.split(' ');

		assert(test[0] == "abc");
		assert(test[1] == "de");
		assert(test[2] == "fgh");
	}
		std::cout<<"//==================================================//"<<'\n';
	{
		String str = " ok here it is";

		std::vector<String> test = str.split(' ');

		assert(test[0] == "ok");
		assert(test[1] == "here");
		assert(test[2] == "it");
		assert(test[3] == "is");
	}
		std::cout<<"//==================================================//"<<'\n';
	{
		String str = "ok here it is ";

		std::vector<String> test = str.split(' ');

		assert(test[0] == "ok");
		assert(test[1] == "here");
		assert(test[2] == "it");
		assert(test[3] == "is");
	}
		std::cout<<"//==================================================//"<<'\n';
	{
		String str = "The sky, it is tough ";

		std::vector<String> test = str.split('t');

		assert(test[0] == "The sky, i");
		assert(test[1] == " is ");
		assert(test[2] == "ough ");
	}
		std::cout<<"//==================================================//"<<'\n';
	{
		String str = "  ";

		std::vector<String> test = str.split(' ');

		assert(test[0] == "");
	}
		std::cout<<"//==================================================//"<<'\n';
	{
		String str = "Hello World!";

		std::vector<String> test = str.split(':');

		assert(test[0] == "Hello World!");
	}
		std::cout<<"//==================================================//"<<'\n';
	{
		String str = "131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] GET /~darci/ HTTP/1.0 200 5625";

		std::vector<String> test = str.split(' ');

		std::cerr<<"test size is: "<<test.size()<<'\n';
		int indx = 0; 
		while(indx < test.size()){
			std::cerr<<"test["<<indx<<"] == "<<test[indx]<<'\n';
			indx++;
		}
	}
		std::cout<<"//==================================================//"<<'\n';

		std::cout<<"Finished Testing split function"<<'\n';
}