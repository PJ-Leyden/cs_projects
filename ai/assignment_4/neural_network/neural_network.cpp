#include "neural_network.hpp"

Neural_Network::Neural_Network(){
	neurons = NULL;
	neurons_per_layer = NULL;
}

Neural_Network::~Neural_Network(){
	if(neurons != NULL){
		for(int i = 0; i < num_layers; i++){
			if(neurons[i] != NULL){
				for(int j = 0; j< neurons_per_layer[i]; j++){
					if(neurons[i][j] != NULL){
						delete neurons[i][j];
					}
				}	
				delete[] neurons[i];
			}
		}
		delete[] neurons;
	}

	if(neurons_per_layer != NULL){
		delete[] neurons_per_layer;
	}
}

void Neural_Network::set_network_parameters(){
	std::cout << "Input the number of layers {at least 3}: ";
	std::cin >> num_layers;
	neurons_per_layer = new int[num_layers];
	for(int i = 0; i < num_layers; i++){
		if(i == 0){
			std::cout << "Input number of input layer neurons: ";
			std::cin >> neurons_per_layer[i];
			std::cout << '\n';
		}else if(i == num_layers - 1){
			std::cout << "Input number of output layer neurons: ";
			std::cin >> neurons_per_layer[i];
			std::cout << '\n';
		}else{
			std::cout << "Input number of hidden layer " << i << " neurons: ";
			std::cin >> neurons_per_layer[i];
			std::cout << '\n';		
		}
	}

	std::cout << "Set threshold: ";
	std::cin >> threshold;
	std::cout << '\n';

	num_input = neurons_per_layer[0];
	num_output = neurons_per_layer[num_layers - 1];

}

void Neural_Network::build_network(){
	//ok, first create all Neurons.
	//then iterate through them and link them with inputs and outputs. 
	//generate weights randomly? Yes.
	srand(time(NULL));//for the weight generator

	//nerons creator
	neurons = new Neuron**[num_layers];//establish top layer array
	for(int i = 0; i < num_layers; i++){
		neurons[i] = new Neuron*[neurons_per_layer[i]];//establish second layer array
		// for every pointer in second layer array create neuron
		for(int j = 0; j < neurons_per_layer[i]; j++){
			//make any init calls to Neuron constructor
			neurons[i][j] = new Neuron();
		}
	}

	//Linking process along with random weights
	for(int i = 0; i < num_layers; i++){//for all neuron layers
		for(int j = 0; j < neurons_per_layer[i]; j++){//for all neurons in each layer
			if(i != 0 ){//make sure not input layer
				for(int k = 0; k <  neurons_per_layer[i - 1] ; k++){//input layer map
					const double w = ((rand() % 201 - 100) / 100.0);//generate random weight
					neurons[i][j]->inputs.insert(std::pair<double, Neuron*>(w, neurons[i - 1][k]));
				}
			}
			if(i != num_layers - 1){//make sure not output layer
				for(int k = 0; k <  neurons_per_layer[i + 1] ; k++){//input layer map
					neurons[i][j]->outputs.push_back(neurons[i + 1][k]);
				}
			}
		}
	}
}

Data Neural_Network::run_network(){

	Data input_data(num_input);
	std::cout << "Enter data points: \n";
	for(int i = 0; i < num_input; i++){
		std::cout << i << ": ";
		std::cin >> input_data.d[i];
		std::cout << '\n';
	}

	for(int i = 0; i < num_layers; i++){//i is layer num
		for(int j = 0; j < neurons_per_layer[i]; j++){//j is neuron number
			//neurons[i][j]->
			if(i == 0){//is input layer
				neurons[i][j]->value = input_data.d[j];
			}
			for(std::pair<double, Neuron*> cur : neurons[i][j]->inputs){
				if(cur.second->value >= threshold){
					neurons[i][j]->value += cur.first * cur.second->value;
				} 
			}
		}
	}

	Data result(num_output);
	for(int i = 0; i < num_output; i++){
		result.d[i] = neurons[num_layers - 1][i]->value;
	}

	return result;

}
