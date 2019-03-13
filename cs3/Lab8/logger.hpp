#ifndef LOGGER_CS3
#define LOGGER_CS3

#include <fstream>
#include <iostream>

class Logger{
public:

	static Logger* instance(){
		static Logger log;
		return &log;
	}

	void report(const std::string &line){
		file << line;
	}

	~Logger(){
		if(file.is_open()){
			file.close();
		}
	}

private:

	Logger(){
		std::cout << "Enter log file name.\nLeave blank for default.\n : ";
		std::getline(std::cin, fileName);

		if(fileName == ""){
			fileName = "log.txt";
		}

		file.open(fileName, std::fstream::app);
		if(!file.is_open()){
			std::cerr << "Could not open file.\n";
			exit(1);
		}
	}

	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	std::string fileName;
	std::ofstream file;

};

#endif