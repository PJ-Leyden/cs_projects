#include "hmm.hpp"

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
	//possible do in constructor
	transitions[1][2] = 5.9;
	emissions[1][2] = 4.0;
}

void HMM::set_transitions_matrix(){

}

void HMM::set_observations(){

}

void HMM::calculate_path(){
	
}

std::ostream& operator<<(std::ostream& out, const HMM& hmm){
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
