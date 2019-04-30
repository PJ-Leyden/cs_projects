#include "process.hpp"

int Process::next_id = 0;

Process::Process(){
	process_id = next_id;
	++next_id;
	state_ = S_New::instance();
}

void Process::admitted(){
	state_->admitted(this);
}

void Process::interrupt(){
	state_->interrupt(this);
}

void Process::exit(){
	state_->exit(this);
}

void Process::event_wait(){
	state_->event_wait(this);
}

void Process::event_complete(){
	state_->event_complete(this);
}

void Process::scheduler_dispatch(){
	state_->scheduler_dispatch(this);
}

void Process::report(std::ostream &out){
	out << "Process " << process_id << " is ";
	state_->report(out);
}

//State Implementation

void S_New::admitted(Process *p){
	p->change_state(Ready::instance());
}

void Ready::scheduler_dispatch(Process *p){
	p->change_state(Running::instance());
}

void Waiting::event_complete(Process *p){
	p->change_state(Ready::instance());
}

void Running::event_wait(Process *p){
	p->change_state(Waiting::instance());
}

void Running::interrupt(Process *p){
	p->change_state(Ready::instance());
}

void Running::exit(Process *p){
	p->change_state(Terminated::instance());
}

