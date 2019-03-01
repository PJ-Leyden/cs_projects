#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main(int argc, char* argv[]){
  
  	if(argc < 3){
		std::cout << "Error: Not enough files.\n\tUsage: ./a.out [input1][input2]\n";
  	}else{
		std::ifstream file1(argv[1]);
		std::ifstream file2(argv[2]);
		std::string line1, line2;// lines coorisponding to each files current line
		int len1 = strlen(argv[1]);
		int len2 = strlen(argv[2]);
		//int diff = abs();
		int count = -1;//for counting line numbers

		std::cout << "=================================\n\n";
		
		while(!file1.eof() || !file2.eof()){

			//if file2 has ended
	  		if(!file1.eof() && file2.eof()){

				++count;
				std::getline(file1, line1);
				//Account for end of line grab
				if(line1 == ""){
					continue;
				}

				//print out lines
				std::cout << argv[1] << ": " << count << ": " << line1 << '\n';
				std::cout << argv[2] << ": " << count << ": \n";

				//print appropriate amount of spaces to move the ^
				int spaces = (count > 9) ? (strlen(argv[1]) + 6) : (strlen(argv[1]) + 5);
				for(int i = 0; i < spaces; ++i){
					std::cout << " ";
				}
				std::cout << "^\n";


			//if file1 has ended
	  		}else if(!file2.eof() && file1.eof()){

	  			++count;
	  			std::getline(file2, line2);
	  			if(line2 == ""){//Account for end of line grab
					continue;
				}

				//print out lines
				std::cout << argv[1] << ": " << count << ": \n";
				std::cout << argv[2] << ": " << count << ": " << line2 << '\n';

				//print appropriate amount of spaces to move the ^
				int spaces = (count > 9) ? (strlen(argv[1]) + 6) : (strlen(argv[1]) + 5);
				for(int i = 0; i < spaces; ++i){
					std::cout << " ";
				}
				std::cout << "^\n";


			//if niether file has ended	
	  		}else{
				++count;
				std::getline(file1, line1);
				std::getline(file2, line2);
				bool found_diff = false;

				int max_length = (line1.length() < line2.length()) ? line1.length() : line2.length();
				for(int i = 0; i < max_length; ++i){
	  				if(line1[i] != line2[i]){

	  					//print out lines
						std::cout << argv[1] << ": " << count << ": " << line1 << '\n';
						std::cout << argv[2] << ": " << count << ": " << line2 << '\n';

						//print appropriate amount of spaces to move the ^
						int spaces = (count > 9) ? (strlen(argv[1]) + i + 6) : (strlen(argv[1]) + i + 5);
						for(int j = 0; j < spaces; ++j){
		  					std::cout << " ";
						}
						std::cout << "^\n";
						found_diff = true;
						break;
	  				}
				}

				if(!found_diff && (line1.length() != line2.length())){//if the only difference is length

					//print out lines
					std::cout << argv[1] << ": " << count << ": " << line1 << '\n';
					std::cout << argv[2] << ": " << count << ": " << line2 << '\n';

					//print appropriate amount of spaces to move the ^
					int spaces = (count > 9) ? (strlen(argv[1]) + max_length + 6) : (strlen(argv[1]) + max_length + 5);
					for(int j = 0; j < spaces; ++j){
		  				std::cout << " ";
					}
					std::cout << "^\n";
				}


	  		}

		}
		std::cout << "=================================\n";

  	}
}
