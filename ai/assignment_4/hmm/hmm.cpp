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
	transitions = NULL;
	emissions = NULL;
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

}

void HMM::set_transitions_matrix(){

}

void HMM::set_observations(){

}

void HMM::calculate_path(){
	
}
