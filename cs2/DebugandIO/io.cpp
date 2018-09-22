//io.cpp
#include <iostream>
#include <fstream>
#include <string>
//================================================================================
void getWord(std::string& word, std::ifstream& wrdStrm){
	word = "";
	char temp = wrdStrm.get();
	while(temp != ' ' && temp != '\n' && !wrdStrm.eof()){
		word += temp;
		temp = wrdStrm.get();
	}
}
//================================================================================
void getLine(std::string& word, std::ifstream& wrdStrm){
	word = "";
	char temp = wrdStrm.get();
	while(temp != '\n' && !wrdStrm.eof()){
		word += temp;
		temp = wrdStrm.get();
	}
}
//================================================================================
int main(int argc, char *argv[]){
	std::ifstream fs;
	fs.open(argv[1]);

	std::string word = " ";

	if(argc == 2){//program name and txt file
		int numberOfWords = -1;
		//getWord(word, fs);
		while(word != ""){
			numberOfWords++;
			getWord(word, fs);
			if(word != ""){
				std::cout<<"The "<<numberOfWords + 1<<" word == "<<word<<std::endl;
			}
		}
		std::cout<<"The number of words = "<<numberOfWords<<std::endl;
		fs.close();
	}
	else if(argc == 3){//program name, txt file, output file
		std::ofstream fs1;
		fs1.open(argv[2]);
		while(word != ""){
			getLine(word, fs);
			fs1 << word << "\n";
		}
		fs.close();
		fs1.close();
	}
	else{
		std::cerr<<"Invaild number of arguments"<<std::endl;
	}
	return 0;
}
//================================================================================