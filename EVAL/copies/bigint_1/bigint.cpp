//bigint.cpp
#include "bigint.hpp"
//==============================================================
bigint::bigint(){//default constr
	for(int i = 0; i < SIZE; i++){//runs through all ele and sets them to zero
		theNumberArray[i] = 0;
	}
}
//==============================================================
bigint::bigint(int numIn){//int constr
	bool stillInNum = true;//tells whether or not we have finished inputing the number
	for(int indx = 0; indx < SIZE; indx++){//cycles through all elements
		if(stillInNum){//while in the number we continue
			theNumberArray[indx] = numIn % 10;
			numIn = numIn / 10;
			if(numIn == 0){//finished number
				stillInNum = false;
				indx++;
			}
		}
		if(!stillInNum){
			theNumberArray[indx] = 0;//fills with zero
		}
	}
}
//==============================================================
bigint::bigint(const char inputNumber[]):bigint(){//char string constr
	/*for(int indx = 0; indx < SIZE; indx++){//fills with zero
		theNumberArray[indx] = 0;
	}*/
	int i = 0;
	int maxIndex = -1;
	while(true){//finds length of inputNumber
		if(inputNumber[i] == '\0'){
			break;
		}
		else{
			maxIndex++;
			i++;
		}
	}
	for(int j = 0; j <= maxIndex; j++){//inputs number
		
		theNumberArray[maxIndex - j] = inputNumber[j] - '0';
	}
}
//==============================================================
bool bigint::operator==(const bigint& rhs) const{
	for(int i = 0; i < SIZE; i++){
		if(theNumberArray[i] == rhs.theNumberArray[i]){
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}
//==============================================================
std::ostream& operator<<(std::ostream& out, const bigint& outNumber){
	int maxIndex = bigint::SIZE - 1;//max index of array
	bool foundStartOfNumber = false;//ok, we have not found the start don't print
	int numPrints = 0;//how many have we printed so we can reset at 50.
	for(int i = maxIndex; i >= 0; i--){
		if(outNumber.theNumberArray[i] != 0){//did we find a non zero? If yes then we found the start
			foundStartOfNumber = true;
		}
		if(!foundStartOfNumber){
			if(i == 0){//if we never find a non zero the number IS zero therfore print a zero
				out<<0;
			}
			continue;
		}
		out<<outNumber.theNumberArray[i];
		numPrints++;
		if(numPrints == 50){
			out<<std::endl;//replace with non standard new line?
		}
	}
	return out;
}
//==============================================================
//std::istream& operator>>(std::istream& in, bigint& inNumber){// we get in stream, we store it in inNumber(which refers to bi of "cin >> bi" then return cin just in case)

//}
//==============================================================
bigint bigint::operator+(const bigint& rhs) const{
	bigint result;
	for(int indx = 0; indx < SIZE; indx++){
		if(result.theNumberArray[indx] + theNumberArray[indx] + rhs.theNumberArray[indx] < 10){
			result.theNumberArray[indx] += (theNumberArray[indx] + rhs.theNumberArray[indx]);
		}
		else if(result.theNumberArray[indx] + theNumberArray[indx] + rhs.theNumberArray[indx] >= 10){
			result.theNumberArray[indx] += (theNumberArray[indx] + rhs.theNumberArray[indx] - 10);
			result.theNumberArray[indx + 1] += 1;
		}
	}
	return result;
}
//==============================================================
int bigint::operator[](int place) const{
	int retNum = 0;
	retNum = theNumberArray[place];
	return retNum;
}
//==============================================================