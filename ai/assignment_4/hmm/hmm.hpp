#ifndef AI_4_HMM
#define AI_4_HMM

#include <list>
#include <iostream>

struct Node{
	char name;
};

class HMM{
private:
	int num_states;
	int num_emissions;
	//std::map<Node, double> init_value_map;
	std::map<int, double> init_value_map;
	//std::list<Node> states;
	double** transitions; // matrix [NS x NS]
	double** emissions; // matrix [NS x NE]
	double* observations; 

public:
	HMM();
	HMM(int, int); // num states and num emissions

	~HMM();

	void set_emissions_matrix();
	void set_transitions_matrix();
	void set_observations();

	void calculate_path(); // ensure have all info 

};

#endif