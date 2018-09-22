//test_part4.cpp
#include "string.hpp"
#include "logentry.hpp"

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <vector>

int main(){
	std::ifstream in("log_1_tiny.txt");
	if(!in) {std::cout<<"You suck"<<'\n';}

	std::vector<LogEntry> log_entries = parse(in);

	std::cout<<"OK, we're here."<<'\n';
}