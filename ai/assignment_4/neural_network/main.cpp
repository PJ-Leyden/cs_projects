#include "neural_network.hpp"
#include "data.hpp"

int main(){

	//create network
	Neural_Network nn;

	//set up size
	nn.set_network_parameters();
	
	//build network
	nn.build_network();

	Data out = nn.run_network();


	std::cout << out;



	return 0;
}