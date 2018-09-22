//bigint.hpp
#ifndef CS2_BIGINT_HPP
#define CS2_BIGINT_HPP
#include <iostream>
class bigint{
	
	public:
		bigint();//default to zero
		bigint(int);//intitialize with int number
		bigint(const char[]);//initialize with char string
		bool operator==(const bigint&) const;//overwrite of == operator
		bigint operator+(const bigint&) const;//possible re-write if only one parameter
		int operator[](int) const;

		friend std::ostream& operator<<(std::ostream&, const bigint&);//overwrite of << operator
		//friend std::istream& operator>>(std::istream&, bigint&);//overwrite of >> operator

	private:
		static const int SIZE = 256;
		int theNumberArray[SIZE];
};
#endif
