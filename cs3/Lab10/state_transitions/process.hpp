#include <iostream>
#include "state.hpp"

class Process{
private:
	static int next_id = 0;
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

