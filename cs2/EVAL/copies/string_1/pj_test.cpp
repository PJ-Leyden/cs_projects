//pj_test.cpp
#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	//============================================================================================
	{//Test Set 1 - Constr, Length, Capacity, Output, Modify and Accessor
		char ary[4] = {'a', 'b', 'c', 'd'};

		String pj;
		String pj1('k');
		String pj2(ary);

		std::cout<<"String pj == "<<pj<<std::endl;
		std::cout<<"String pj1 == "<<pj1<<std::endl;
		std::cout<<"String pj2 == "<<pj2<<std::endl;

		std::cout<<"The length of String pj2 == "<<pj2.length()<<std::endl;

		std::cout<<"The capacity of String pj2 == "<<pj2.capacity()<<std::endl;

		std::cout<<"Char at index 2 of pj2 == "<<pj2[2]<<std::endl;

		pj2[2] = 'p';

		std::cout<<"Char at index 2 of pj2 is now == "<<pj2[2]<<std::endl;

		std::cout<<"Finished Testing Constr, Length, Capacity, Output, Modify and Accessor"<<std::endl;
	}
	//============================================================================================
	{//Test Set 2 - ==
		char ary1[6] = "abcde";
		char ary2[6] = "abcde";
		char ary3[6] = "aaaaa";
		char ary4[7] = "abcdef";

		String pj1;
		String pj2;
		std::cerr<<"================================================================"<<std::endl;
		String pj3(ary1);
		String pj4(ary2);
		String pj5(ary3);
		String pj6(ary4);
		std::cerr<<"================================================================"<<std::endl;
		assert(pj1 == pj2);
		assert(pj3 == pj4);
		assert(!(pj3 == pj5));
		assert(!(pj3 == pj6));

		std::cout<<"Finished Testing =="<<std::endl;
	}
	//============================================================================================
	{//Test Set 2.5 Length Comparison
		/*std::string cool = "abcde";
		std::string cool2 = "Azzzzzzzzzzzzzzzzzzzzzzzz";
		bool res = cool2 < cool;
		if(res){
			std::cout<<"True"<<std::endl;
		}
		else{
			std::cout<<"False"<<std::endl;
		}*/
	}
	//============================================================================================
	{//Test Set 3 - <
		char ary1[] = "ABCDE";
		char ary2[] = "ABCDE";
		char ary3[] = "abcdefghijkl";
		char ary4[] = "ABCD";
		char ary5[] = "a";

		String pj1 = ary1;
		String pj2 = ary2;
		String pj3 = ary3;
		String pj4 = ary4;
		String pj5 = ary5;
		//============================
		assert(!(pj1 < pj2));
		assert(pj1 < pj3);
		assert(pj4 < pj1);
		assert(!(pj1 < pj4));
		assert(!(pj5 < pj1));
		assert(pj1 < pj5);

		std::cout<<"Finished Testing <"<<std::endl;
	}
	//============================================================================================
	{//Test Set 4 - +
		char ary1[] = "AABBCCDD";
		char ary2[] = "EEFFGGHH";

		String pj1(ary1);
		String pj2(ary2);

		String pj3 = pj1 + pj2;

		std::cout<<pj3<<std::endl;

		//====================================

		char ary3[] = "12345.,sjh";
		char ary4[] = "abffdcsujk";

		String pj4(ary3);
		String pj5(ary4);

		String pj6 = pj4 + pj5;

		std::cout<<pj6<<std::endl;
	}
	//============================================================================================
	{//Test Set 5 -
		char ary[5] = "abcd"; 
		String pj(ary);
		
		char ary1[5] = "abcd";

		std::cout<<pj<<" == ";
		for(int i = 0; i < 4; i++){
			std::cout<<ary1[i];
		}
		std::cout<<std::endl;

		assert(ary1 == pj);
	}
	return 0;
}