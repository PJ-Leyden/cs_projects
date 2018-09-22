//File: test_split.cpp
//Author: P.J. Leyden
//Test: split
#include "string.hpp"
#include <iostream>
#include <vector>
int main(){
	{
		String str = "abc de fgh";
		
		std::vector<String> test = str.split(' ');

		for(int i = 0; i < test.size(); i++){
			std::cout<<test[i]<<'\n';
		}
		std::cout<<"//==================================================//"<<'\n';
	}
//=====================================================
	{
		String str = " ok here it is";

		std::vector<String> test = str.split(' ');

		for(int i = 0; i < test.size(); i++){
			std::cout<<test[i]<<'\n';
		}
		std::cout<<"//==================================================//"<<'\n';
	}
//=====================================================
	{
		String str = "ok here it is ";

		std::vector<String> test = str.split(' ');

		for(int i = 0; i < test.size(); i++){
			std::cout<<test[i]<<'\n';
		}
		std::cout<<"//==================================================//"<<'\n';
	}
//=====================================================
	{
		String str = "The sky, it is tough ";

		std::vector<String> test = str.split('t');

		for(int i = 0; i < test.size(); i++){
			std::cout<<test[i]<<'\n';
		}
		std::cout<<"//==================================================//"<<'\n';
	}
//=====================================================
	{
		String str = "  ";

		std::vector<String> test = str.split(' ');

		for(int i = 0; i < test.size(); i++){
			std::cout<<test[i]<<'\n';
		}
		std::cout<<"//==================================================//"<<'\n';
	}

}