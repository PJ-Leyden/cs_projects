//bigint.cpp
#include "bigint.hpp"
//======================================================================
bigint::bigint()//default
{
	for(int i = 0; i < SIZE; i++)
	{
		theNumber[i] = 0;
	}
	//std::cerr<<theNumber[255]<<std::endl;
}
//======================================================================
bigint::bigint(int bigNum)
{
	int i = 0;
	bool firstRun = true;
	while(true)
	{
		theNumber[i] = bigNum % 10;
		std::cerr<<"true number"<<theNumber[i]<<std::endl;
		bigNum = bigNum / 10;
		//=============================
		if(bigNum == 0 && firstRun)
		{
			for(int j = i + 1; j < SIZE; j++)
			{
				theNumber[j] = 0;
			}
			break;
		}
		//=============================
		firstRun = false;
		if(bigNum == 0 && !firstRun)
		{
			for(int k = i + 1; k < SIZE; k++)
			{
				theNumber[k] = 0;
			}
			break;
		}
	}
	//std::cout<<theNumber<<std::endl;
	//std::cerr<<"Left 2"<<std::endl;
}
//======================================================================
bigint::bigint(const char inputNumber[])//set number
{
	std::cerr<<"Here"<<std::endl;
	//=============================== Planning to take out with ": bigint();"
	for(int i = 0; i < SIZE; i++)
	{
		theNumber[i] = 0;
	}
	//===============================
	int i = 0;
	while(true)
	{
		if(inputNumber[i] == '\0')
		{
			std::cerr<<"Found null"<<std::endl;
			break;
		}
		else
		{
			std::cout<< (int)inputNumber[i] - '0' <<std::endl;
			theNumber[i] = (int)inputNumber[i] - '0';
			i++;
		}
	}
}
//======================================================================
bool bigint::operator==(const bigint& rhs) const//ugh... allows for use of == between bigints
{
	int i = 0;
	while(true)
	{
		if(theNumber[i] == rhs.theNumber[i])
		{
			if(i == (SIZE - 1))
			{
				return true;
			}
			i++;
			continue;
		}
		else
		{
			return false;
		}
	}
}
//=====================================================================
std::ostream& operator<<(std::ostream& out, const bigint& rhs)
{
	int i = bigint::SIZE - 1;
	bool foundNumber = false;
	while(0 <= i)
	{
		if((rhs.theNumber[i] == 0) && (!foundNumber))
		{
			i--;
			if(i == 0)
			{
				//out<<rhs.theNumber[i]<<std::endl;
				break;
			}
			continue;
		}
		foundNumber = true;
		//std::cout<<"true Number "<<rhs.theNumber[i]<<std::endl;
		//out<<rhs.theNumber[i];
		--i;
	}
	return out;
}
