//fileio.cpp
#include <iostream>
#include <fstream>

int main(){
	//===================================================
	{//Lab 5 First Part
		std::ifstream fileData("data1-1.txt");
		if(!fileData.is_open()){
			return 0;
		}
		char buf;
		while(!fileData.eof()){
			fileData >> buf;
			std::cout<< buf;
		}
		fileData.close();
	}
	//===================================================
	{//Lab 5 Second Part
		std::ifstream fileData("data1-1.txt");
		if(!fileData.is_open()){
			return 0;
		}
		char buf;
		while(!fileData.eof()){
			fileData.get(buf);
			if(buf == ' '){
				std::cout<<"\n";
				break;
			}
			std::cout<< buf;
		}
		fileData.close();
	}
	//===================================================
	{//Lab 5 Third Part
		std::ifstream fileData("data1-1.txt");
		if(!fileData.is_open()){
			return 0;
		}
		int buf1;
		int buf2;
		int result;
		while(!fileData.eof()){
			fileData >> buf1;
			std::cout<<buf1<<std::endl;
			fileData >> buf2;
			std::cout<<buf2<<std::endl;
			result = buf1 + buf2;
			std::cout<< result;
			break;
		}
		fileData.close();
	}
}