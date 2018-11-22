#include "hmm.hpp"

int main(){

	HMM hmm(5, 6);

	hmm.set_emissions_matrix();

	std::cout << hmm << std::endl;

	//Understand that the states and emissions
	//are represented as numbers
	//ex. emission {1, 2, 3 ...} or state {1, 2, 3 ...}

	//init HMM

	//set num of states and emissions

	//set init probability map

	//set transition matrix and emissions matrix

	//give observations

	//calculate the most probable path
	

	return 0;
}