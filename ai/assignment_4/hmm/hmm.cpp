#include "hmm.hpp"

void probability(std::string& seq, double odds, int next_state, int depth, std::map<std::string, double>* pp, HMM& hmm){
	std::cerr << "Depth: " << depth << '\n';
	if(depth == hmm.num_observations){
		std::cerr << "End Depth\n";
		std::pair<std::string, double> temp(seq, odds);
		std::cerr << "Temped\n";
		pp->insert( temp );
		std::cerr << "Finished End Depth\n";
	}else if(hmm.emissions[next_state][hmm.observations[depth]] == 0){
		std::cerr << "0 Chance\n";
		return;
	}else{
		std::cerr << "Inner Transitions\n";
		for(int i = 0; i < hmm.num_states; i++){//possible transitions for next_state
			std::cerr << "Inner Transition: " << i << '\n';
			if(hmm.transitions[next_state][i] != 0){
				seq = seq + std::to_string(i);
				odds = odds * hmm.emissions[next_state][hmm.observations[depth]] * hmm.transitions[next_state][i];
				probability(seq, odds, i, depth + 1, pp, hmm);
			}
		}
	}
}

HMM::HMM(){
	num_states = 0;
	num_emissions = 0;
	transitions = NULL;
	emissions = NULL;
	observations = NULL;
}

HMM::HMM(int st, int em){
	num_states = st;
	num_emissions = em;

	transitions = new double*[num_states];
	for(int i = 0; i < num_states; i++){
		transitions[i] = new double[num_states];
	}

	emissions = new double*[num_states];
	for(int i = 0; i < num_states; i++){
		emissions[i] = new double[num_emissions];
	}

	observations = NULL;
}

HMM::~HMM(){
	if(transitions != NULL){
		for(int i = 0; i < num_states; i++){
			if(transitions[i] != NULL){
				delete[] transitions[i];
			}
		}
		delete[] transitions;
	}

	if(emissions != NULL){
		for(int i = 0; i < num_states; i++){
			if(emissions[i] != NULL){
				delete[] emissions[i];
			}
		}
		delete[] emissions;
	}

	if(observations != NULL){
		delete[] observations;
	}
}

void HMM::set_emissions_matrix(){
	//each node needs to have 1 as the sum total probability of leaving. 
	//The matrix is state by state ot state to state x to y
	//columns should add up to 1 
	srand(time(NULL) * 2);
	for(int i = 0; i < num_states; i++){
		double hundred = 100.0;
		std::vector<double> weights;
		for(int j = 0; j < num_emissions; j++){
			double random = rand() % 101;
			if(j == num_states - 1){
				weights.push_back(hundred / 100.0);
			}else{
				if(hundred == 0){
					weights.push_back(0.0);
				}else{
					if(hundred - random < 0){
						weights.push_back(hundred / 100.0);
						hundred = 0;
					}else{
						weights.push_back(random / 100.0);
						hundred -= random;
					}
				}
			}
		}
		std::random_shuffle(weights.begin(), weights.end());
		for(int j = 0; j < num_emissions; j++){
			emissions[i][j] = weights[j];
		}
	}
}

void HMM::set_transitions_matrix(){
	//each node needs to have 1 as the sum total probability of leaving. 
	//The matrix is state by state ot state to state x to y
	//columns should add up to 1 
	srand(time(NULL));
	for(int i = 0; i < num_states; i++){
		double hundred = 100.0;
		std::vector<double> weights;
		for(int j = 0; j < num_states; j++){
			double random = rand() % 101;
			if(j == num_states - 1){
				weights.push_back(hundred / 100.0);
			}else{
				if(hundred == 0){
					weights.push_back(0.0);
				}else{
					if(hundred - random < 0){
						weights.push_back(hundred / 100.0);
						hundred = 0;
					}else{
						weights.push_back(random / 100.0);
						hundred -= random;
					}
				}
			}
		}
		std::random_shuffle(weights.begin(), weights.end());
		for(int j = 0; j < num_states; j++){
			transitions[i][j] = weights[j];
		}
	}
}

void HMM::set_observations(){
	std::cout << "Enter the number of observations: ";
	std::cin >> num_observations;
	std::cout << '\n';
	observations = new int[num_observations];
	for(int i = 0; i < num_observations; i++){
		std::cout << "Enter an observation. {1, 2, 3, ... etc.}: ";
		std::cin >> observations[i];
		std::cout << '\n';
	}
}

void HMM::set_init_values(){

	double hundred = 100.0;
	std::vector<double> weights;
	for(int j = 0; j < num_states; j++){
		double random = rand() % 101;
		if(j == num_states - 1){
			weights.push_back(hundred / 100.0);
		}else{
			if(hundred == 0){
				weights.push_back(0.0);
			}else{
				if(hundred - random < 0){
					weights.push_back(hundred / 100.0);
					hundred = 0;
				}else{
					weights.push_back(random / 100.0);
					hundred -= random;
				}
			}
		}
	}

	std::random_shuffle(weights.begin(), weights.end());
	for(int j = 0; j < num_states; j++){
		init_value_map.insert(std::pair<int, double>(j+1, weights[j]));
	}

}

void HMM::calculate_path(){
	std::map<std::string, double>* path_prob;
	int count = 0;
	for(std::pair<int, double> init : init_value_map){
		if(std::get<1>(init) != 0){
			std::string seq = std::to_string(std::get<0>(init));
			double odds = std::get<1>(init);
			int ns = std::get<0>(init);
			int depth = 0;
			std::cout << "Called Main Probability: " << count << '\n';
			probability(seq, odds, ns, depth, path_prob, *this);
			count++;
		}
	}

	std::cout << "DONE!\n";

	for(std::pair<std::string, double> path : *path_prob){
		std::cout << "Path: " << path.first << " = " << path.second << '\n';
	}
	//calculate all possible paths that create said observation sequence. 
	//take the most probable path
	//for each possible init state
		//calculate probability of it running with the first obser
		//add next_transtion next transition should be (trans * emisssion on next state)
			//next_transition should calculate the probabilty of the next transtion and return it. 
			//ends if probability is zero. simply return zero.
	//recursion to dig into the path of the tree
	//helper function called next_transition returns
	//so many possibilites...
}

std::ostream& operator<<(std::ostream& out, const HMM& hmm){
	out << "Init Values: \n";
	for(std::pair<int, double> init : hmm.init_value_map){
		out << "{" << std::get<0>(init) << " , " << std::get<1>(init);
		out << "}\n";
	}

	out << '\n';

	out << "Transitions Matrix: \n";
	for(int i = 0; i < hmm.num_states; i++){
		out << '|';
		for(int j = 0; j < hmm.num_states; j++){
			out << hmm.transitions[j][i] << '\t' << '|';
		}
		out << '\n';
	}
	out << '\n';
	out << "Emissions Matrix: \n";
	for(int i = 0; i < hmm.num_emissions; i++){
		out << '|';
		for(int j = 0; j < hmm.num_states; j++){
			out << hmm.emissions[j][i] << '\t' << '|';
		}
		out << '\n';
	}

	return out;
}


