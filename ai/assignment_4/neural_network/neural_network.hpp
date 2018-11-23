#ifndef AI_4_NETWORK
#define AI_4_NETWORK

#include "neuron.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//I recognize that the best thing to do would be to make this a template class
//allowing for any data set to be trained. However, within reason I decided
//against doing that. 

class Neural_Network{
private:
	//neurons per layer neurons[x][y], x is layer number, y is node in layer.
	//gives a pointer used with ->
	//Ex. neurons[i][j]->taco(); 
	Neuron*** neurons;//this disgusts me. 

	//at least 3, one input, one output, and one hidden.
	int num_layers = 3;

	//arary for determing number of neurons per layer
	//Ex. Num neurons in input layer = neurons_per_layer[0];
	int* neurons_per_layer;

public:
	Neural_Network();
	~Neural_Network();

	void set_network_parameters(); //setting num_layers and neurons_per_layer
	void build_network(); //this is gonna be a pain...





};

#endif