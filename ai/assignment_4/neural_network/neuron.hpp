#ifndef AI_4_NEURON
#define AI_4_NEURON

#include <vector>
#include <map>
#include <iostream>


class Neuron{
public:
	//Each neuron is linked to its previuos and next layers fully
	//it only maintains the weights for the edges leading to the 
	//previuos layer
	std::map<double, Neuron*>  inputs;
	double                     value;
	std::vector<Neuron*>       outputs;

	Neuron();
};

#endif 