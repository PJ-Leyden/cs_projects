#include "process.hpp"

class State{
public:
	void admitted(Process*){}
	void interrupt(Process*){}
	void exit(Process*){}
	void event_wait(Process*){}
	void event_complete(Process*){}
	void scheduler_dispatch(Process*){}

	virtual void report(std::ostream&) = 0;

	//void change_state(Process *p, State *s){p->change_state(s);}
};


class S_New : public State{
private:
	S_New(){}
public:
	static State* instance(){
		static State* onlyInstance = new S_New(); 
		return onlyInstance;
	}

	void admitted(Process *p) override{
		p->change_state(instance());
	}

	void report(std::ostream &out) override{
		out << "NEW\n";
	}

};


class Ready : public State{

};

class Waiting : public State{

};

class Running : public State{

};

class Terminated : public State{

};