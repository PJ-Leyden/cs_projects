#include "neural_network.hpp"

int main(){

	//create network
	Neural_Network nn;

	//set up size
	nn.set_network_parameters();
	
	//build network
	nn.build_network();

	return 0;
}