//File: test_parse.cpp
//Author: P.J. Leyden
//Date: April 5th, 2016

#include "string.hpp"
#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>

int main(){
	{
		std::ifstream in("testing.txt");
		if(!in){std::cerr<<"Couldn't open\n";}

		std::vector<String> express = parse(in);

		for(int i = 0; i < (int)express.size(); ++i){
			String test = express[i];
			std::cout<<"Line "<<i<<" == "<<"|"<<test<<"|"<<'\n';
		}
	}
	return 0;
}