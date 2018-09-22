//fib.cpp
//P.J. Leyden
//March 8th, 2016

#include <iostream>

int fib(int fibNum){
	if(fibNum == 1){
		return 1;
	}
	else if(fibNum == 0){
		return 0;
	}
	else{
		return (fib(fibNum - 1) + fib(fibNum - 2));
	}
}

int main(){
	std::cout<<"0, 1, 1, ";
	int times = 10;
	int curNum = 3;
	while(times > 3){
		std::cout<<fib(curNum)<<", ";
		--times;
		++curNum;
	}
	std::cout<<'\n';

	return 0;
}