//pj_test.cpp
#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	//============================================================================================
	{//Test Set 1 - Constr, Length, Capacity, Output, Modify and Accessor
		char ary[] = "abcd";
		char aryK[] = "k";

		String pj;
		String p;

		String pj1('k');
		String p1('k');

		String pj2(ary);
		String p2(ary);

		String pjk(aryK);

		//std::cout<<"String pj == "<<pj<<std::endl;
		assert(pj == "");
		assert(pj == '\0');
		//std::cout<<"String pj1 == "<<pj1<<std::endl;
		assert(pj1 == 'k');
		assert(pj1 == "k");
		//std::cout<<"String pj2 == "<<pj2<<std::endl;
		assert(pj2 == "abcd");

		//std::cout<<"The length of String pj2 == "<<pj2.length()<<std::endl;
		assert(pj2.length() == 4);

		//std::cout<<"The capacity of String pj2 == "<<pj2.capacity()<<std::endl;
		assert(pj2.capacity() == 256);

		//std::cout<<"Char at index 2 of pj2 == "<<pj2[2]<<std::endl;
		assert(pj2[2] == 'c');
		pj2[2] = 'p';

		//std::cout<<"Char at index 2 of pj2 is now == "<<pj2[2]<<" - Sould print out 'p' "<<std::endl;
		assert(pj2[2] == 'p');
		pj2[2] = 'c';

		//Asserts
		assert(pj == p);
		assert(pj1 == p1);
		assert(pj2 == p2);
		assert(pjk == pj1);

		std::cout<<"Finished Testing Constr, Length, Capacity, Output, Modify and Accessor"<<std::endl;
	}
	//============================================================================================
	{//Test Set 1.1
		char pj1[5] = "abcd";
		char pj2[5] = "efgh";
		char pj3[2] = "k";

		String ps1(pj1);
		String ps2(pj2);
		String ps3(pj3);
		String ps4('k');


		assert(!(pj1 == pj2));
		assert(ps3 == ps4);
	}
	//============================================================================================
	{//Test Set 1.5 - Copy, Equals, sawp, resetcap
		String temp("abcd");
		assert(temp == "abcd");
		String temp2("efgh");
		assert(temp2 == "efgh");
		temp = temp2;
		assert(temp == temp2);

		String cp(temp);

		assert(cp == temp2);
		assert(temp == "efgh");

		String pj1("abcd");
		String pj2("efgh");
		pj1.swap(pj2);
		assert(pj1 == "efgh");
		assert(pj2 == "abcd");

		String Cool("1234abcd");
		assert(Cool.capacity() == 256);
		Cool.resetCapacity(18);
		assert(Cool.capacity() == 18);

		std::cout<<"Finished Testing Copy, Equals, Swap, ResetCap"<<std::endl;
	}
	//============================================================================================
	{//Test Set 2 - ==
		char ary1[6] = "abcde";
		char ary2[6] = "abcde";
		char ary3[6] = "aaaaa";
		char ary4[7] = "abcdef";

		String pj1;
		String pj2;
		String pj3(ary1);
		String pj4(ary2);
		String pj5(ary3);
		String pj6(ary4);
		assert(pj1 == pj2);
		assert(pj3 == pj4);
		assert(!(pj3 == pj5));
		assert(!(pj3 == pj6));

		std::cout<<"Finished Testing =="<<std::endl;
	}
	//============================================================================================
	{//Test Set 2.5 Length Comparison
		std::string cool = "abcde";
		std::string cool2 = "Azzzzzzzzzzzzzzzzzzzzzzzz";
		bool res = cool2 < cool;
		if(res){
			//std::cout<<"True"<<std::endl;
		}
		else{
			//std::cout<<"False"<<std::endl;
		}
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
		assert(pj4 < pj1);//ABCD < ABCDE
		assert(!(pj1 < pj4));
		assert(!(pj5 < pj1));
		assert(pj1 < pj5);

		std::cout<<"Finished Testing <"<<std::endl;
	}
	//============================================================================================
	{//Test Set 4 - +
		char ary1[] = "AA bb CC dd";
		char ary2[] = "EE ff GG hh";
		char aryTest[] = "AA bb CC ddEE ff GG hh";

		String pj1(ary1);
		String pj2(ary2);
		String pjTest(aryTest);

		String pj3 = pj1 + pj2;
		//std::cout<<"Length == "<<pj3.length()<<std::endl;
		//std::cout<<"Capacity == "<<pj3.capacity()<<std::endl;
		//std::cout<<pj3<<" == "<<pjTest<<std::endl;
		assert(pj3 == pjTest);
		assert(pj3 == "AA bb CC ddEE ff GG hh");
		

		//====================================

		char ary3[] = "12345.,sjh";
		char ary4[] = "abffdcsujk";

		String pj4(ary3);
		String pj5(ary4);

		String pj6 = pj4 + pj5;
		assert(pj6 == "12345.,sjhabffdcsujk");
		//std::cout<<pj6<<std::endl;

		std::cout<<"Finished Testing Addition Operator"<<std::endl;
	}
	//============================================================================================
	{//Test Set 5 - == 
		char ary[5] = "abcd"; 
		String pj(ary);
		
		char ary1[5] = "abcd";

		//std::cout<<pj<<" == ";
		//for(int i = 0; i < 4; i++){
			//std::cout<<ary1[i];
		//}
		//std::cout<<std::endl;

		assert(ary1 == pj);

		std::cout<<"Finished Testing == Part 2"<<std::endl;
	}
	//============================================================================================
	{//Test Set 5.5 - All Operator Types
		String pj1 = "abcd";
		String pj2 = "ABCD";
		String pj3 = "ABCD";
		String pj4 = "ABCDE";
		String pj5 = "Abcde";
		String pj6 = "efgh";

		assert(pj2 < pj1);
		assert(pj1 > pj2);

		assert(pj2 <= pj1);
		assert(pj1 >= pj2);

		assert(pj2 >= pj3);
		assert(pj2 <= pj3);

		assert(pj4 > pj3);
		assert(pj4 >= pj3);
		assert(pj1 > 'K');
		assert('Z' > pj4);
		assert("abcd" < pj6);
		assert("abcd" <= pj6);

		std::cout<<"Finished Testing Extranious Operators"<<std::endl;
	}
	//============================================================================================
	{//Test Set 6 - substr
		String pj = "abcdepjthisone";
		//std::cout<<pj<<std::endl;

		String pj1 = pj.substr(5, 2);

		String pj2 = "pj";

		assert(pj1 == pj2);

		std::cout<<"Finished Testing substr"<<std::endl;
	}
	//============================================================================================
	{//Test Set 7 - findstr
		String pj = "helloworldmynnameistom";
		int pj1 = pj.findstr("hello");
		assert(pj1 == 0);

		int pj2 = pj.findstr("world");
		assert(pj2 == 5);

		int pj3 = pj.findstr("name");
		assert(pj3 == 13);

		int pj4 = pj.findstr("tomato");
		assert(!(pj4 == 19));
		assert(pj4 == -1);

		int pj5 = pj.findstr("tome");
		assert(!(pj5 == 19));
		assert(pj5 == -1);

		String str = "HeLLohello";
		int pj6 = str.findstr("hello");
		assert(pj6 == 5);

		std::cout<<"Finished Testing findstr"<<std::endl;
	}
	//============================================================================================
	{//Test Set 8 - findchar
		String pj = "abcdefgggadegkky";
		int pj1 = pj.findchar('a');
		assert(pj1 == 0);

		int pj2 = pj.findchar('y');
		assert(pj2 == 15);

		int pj3 = pj.findchar('g');
		assert(pj3 == 6);

		int pj4 = pj.findchar('g');
		assert(!(pj4 == 7));

		std::cout<<"Finished Testing findchar"<<std::endl;
	}
	//============================================================================================
	return 0;
}