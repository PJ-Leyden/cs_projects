#ifndef AI_4_HMM
#define AI_4_HMM

#include <list>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <vector>

//struct Node{
//	char name;
//};

class HMM{
private:
	int num_states;
	int num_emissions;
	int num_observations;
	//std::map<Node, double> init_value_map;
	std::map<int, double> init_value_map;// probablity of starting node
	std::map<std::string, double> path_prob;// probabilities of paths for set of observations
	//std::list<Node> states;
	double** transitions; // matrix [NS x NS]
	double** emissions; // matrix [NS x NE]
	int* observations; 

public:
	HMM();
	HMM(int, int); // num states and num emissions

	~HMM();

	void set_emissions_matrix();
	void set_transitions_matrix();
	void set_observations();
	void set_init_values();

	void probability(std::string, double, int, int);
	void calculate_path(); // ensure have all info 

	
	friend std::ostream& operator<<(std::ostream&, const HMM&);

};

#endif