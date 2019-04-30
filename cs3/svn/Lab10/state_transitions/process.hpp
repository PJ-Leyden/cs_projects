#ifndef STATE_CS3
#define STATE_CS3

#include <iostream>
#include <string>

class State;

class Process{
private:
	static int next_id;
	int process_id;
	State *state_;

public:
	Process();

	void admitted();
	void interrupt();
	void exit();
	void event_wait();
	void event_complete();
	void scheduler_dispatch();

	void report(std::ostream&);

	void change_state(State *s){state_ = s;}
};

//int Process::next_id = 0;

class State{
public:
	virtual void admitted(Process*){}
	virtual void interrupt(Process*){}
	virtual void exit(Process*){}
	virtual void event_wait(Process*){}
	virtual void event_complete(Process*){}
	virtual void scheduler_dispatch(Process*){}

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

	void admitted(Process *p) override;

	void report(std::ostream &out) override{
		out << "NEW\n";
	}

};


class Ready : public State{
private:
	Ready(){}
public:
	static State* instance(){
		static State* onlyInstance = new Ready(); 
		return onlyInstance;
	}

	void scheduler_dispatch(Process *p) override;

	void report(std::ostream &out) override{
		out << "READY\n";
	}
};

class Waiting : public State{
private:
	Waiting(){}
public:
	static State* instance(){
		static State* onlyInstance = new Waiting(); 
		return onlyInstance;
	}

	void event_complete(Process *p) override;

	void report(std::ostream &out) override{
		out << "WAITING\n";
	}
};

class Running : public State{
private:
	Running(){}
public:
	static State* instance(){
		static State* onlyInstance = new Running(); 
		return onlyInstance;
	}

	void exit(Process *p) override;
	void event_wait(Process *p) override;
	void interrupt(Process *p) override;

	void report(std::ostream &out) override{
		out << "RUNNING\n";
	}
};

class Terminated : public State{
private:
	Terminated(){}
public:
	static State* instance(){
		static State* onlyInstance = new Terminated(); 
		return onlyInstance;
	}

	void report(std::ostream &out) override{
		out << "TERMINATED\n";
	}
};

#endif