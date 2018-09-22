//fibtr.cpp
//P.J. Leyden
//March 8th, 2016
#include <iostream>
void fibtr(int prevNum, int topNum, int counter){
	if(counter == 2){
		return;
	}
	int nextNum = prevNum + topNum;
	std::cout<<nextNum<<", ";
	fibtr(topNum, nextNum, counter - 1);
}

int main(){
	std::cout<<"0, 1, ";
	fibtr(0, 1, 10);
	std::cout<<'\n';

	return 0;
}