//File: main.cpp
//Code by: P.J. Leyden
//Date: Jan 22nd, 2019

#include "word_count.hpp"
#include <fstream>
#include <cctype>

int main(int argc, char* argv[]){

	if(argc < 2){
		std::cout << "Need a file:\n\tUsage: ./word_count [file]\n";
	}

	std::ifstream input_file(argv[1]);

	WordList wordlist;
	std::string cur_line;

	while(!input_file.eof()){
		//get each line in succession
		std::getline(input_file, cur_line);
		int marker = 0;
		//for each char we will check if it is a delimeter
		for(int indx = 0; indx < cur_line.length(); ++indx){
			if(isalnum(cur_line[indx])){ 
				marker = indx; 
				while(isalnum(cur_line[marker]) && marker < cur_line.length()){
					++marker;
				}
				std::string word = cur_line.substr(indx, marker - indx);
				wordlist.addWord(word);
				indx = marker - 1;
			}
		}
	}

	wordlist.print();

	input_file.close();

	return 0;	
} 