#include "process.hpp"

Process::Process(){
	process_id = next_id;
	++next_id;
	state_ = nullptr;
}

void Process::admitted(){

}

void Process::report(std::ostream &out){
	out << "Process " << process_id << " is ";
	state_->report(out);
}

