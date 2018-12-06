#include "hmm.hpp"

int main(){

	std::cout << "Enter number of states: ";
	int states;
	std::cin >> states;
	std::cout << '\n';

	std::cout << "Enter number of emissions: ";
	int emissions;
	std::cin >> emissions;
	std::cout << '\n';

	HMM hmm(states, emissions);

	hmm.set_transitions_matrix();

	hmm.set_emissions_matrix();

	hmm.set_observations();

	hmm.set_init_values();

	std::cout << hmm << std::endl;

	hmm.calculate_path();	

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