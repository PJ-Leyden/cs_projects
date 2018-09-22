//File: test_resetCap.cpp
//Author: P.J. Leyden
//Date: March 16th, 2016

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	{
		String str = "abcd";
		std::cout<<"The String == "<<str<<" The Capacity is "<<str.capacity()<<'\n';
		assert(str.capacity() == 256);
		str.resetCapacity(12);
		std::cout<<"The String == "<<str<<" The Capacity is "<<str.capacity()<<'\n';
		assert(str.capacity() == 12);
		assert(str == "abcd");
		str.resetCapacity(2);
		std::cout<<"The String == "<<str<<" The Capacity is "<<str.capacity()<<'\n';
	}

		std::cout<<"//==============================================================================================="<<'\n';

	{
		String str = "f";
		std::cout<<"The String == "<<str<<" The Capacity is "<<str.capacity()<<'\n';
		assert(str.capacity() == 256);
		str.resetCapacity(2);
		std::cout<<"The String == "<<str<<" The Capacity is "<<str.capacity()<<'\n';
		assert(str.capacity() == 2);
		assert(str == "f");
		str = "s";
		assert(str == 's');
		assert(str == "s");
		std::cout<<"The String == "<<str<<" The Capacity is "<<str.capacity()<<'\n';
		str.resetCapacity(1);
		assert(str == 's');
		assert(str == "s");
		str.resetCapacity(0);
		assert(str == 's');
		assert(str == "s");
		std::cout<<"The New String == "<<str<<" The Capacity is "<<str.capacity()<<'\n';
	}

		std::cout<<"//==============================================================================================="<<'\n';

	{
		String str = "f";
		std::cout<<"The String == "<<str<<" The Capacity is "<<str.capacity()<<'\n';
		std::cout<<"The Strings length == "<<str.length()<<'\n';
		assert(str == "f");
		assert(str == 'f');
		assert(str.capacity() == 256);
		std::cout<<"--------------------------------------"<<'\n';
		str.resetCapacity(10);
		std::cout<<"The String == "<<str<<" The Capacity is "<<str.capacity()<<'\n';
		std::cout<<"The Strings length == "<<str.length()<<'\n';
		assert(str == "f");
		assert(str == 'f');
		assert(str.capacity() == 10);
		std::cout<<"--------------------------------------"<<'\n';
		str.resetCapacity(1);
		std::cout<<"The String == "<<str<<" The Capacity is "<<str.capacity()<<'\n';
		std::cout<<"The Strings length == "<<str.length()<<'\n';
		assert(str == "f");
		assert(str == 'f');
		assert(str.capacity() == 2);
		std::cout<<"--------------------------------------"<<'\n';
	}

	std::cout<<"Finished Testing resCap"<<'\n';

}