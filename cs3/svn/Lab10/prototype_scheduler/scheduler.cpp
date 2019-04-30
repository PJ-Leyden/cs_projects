#include <queue>
#include <set>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "process.hpp"

class Scheduler{
private:
	Process* prototype;

	std::deque<Process*> all;
	std::queue<Process*> ready;
	std::set<Process*> waiting;

public:
	Scheduler(){
		prototype = new Process();
	}

	void report(std::ostream&);

	void create_process();
	void run(int); // runs an int amount of transitions

};

void Scheduler::report(std::ostream &out){
/*	
	out << "Report: READY\n";
	for(Process *p : ready){
		p->report(out);
	}
	out << "Report: WAITING\n";
	for(Process *p : waiting){
		p->report(out);
	}
	out << "End\n";
*/
	out << "=========================\nReport: \n";
	for(Process *p : all){
		if(p != nullptr)
			out << "\t";
			p->report(out);
	}
	out << "End\n=========================\n";
}

void Scheduler::create_process(){
	Process *temp = prototype->clone();
	temp->admitted();
	ready.push(temp);
	all.push_back(temp);
}

void Scheduler::run(int num){
	srand(time(nullptr));
	for(int i = 0; i < num; ++i){ // creates at least num process
		create_process();
	}

	report(std::cout);

	for(int i = 0; i < num; ++i){

		if(rand()%2 && !waiting.empty()){// 50% of a waiting task being readied
			Process *p = *(waiting.begin());
			waiting.erase(waiting.begin());
			p->event_complete();
			ready.push(p);
			std::cout << "Process " << p->get_process_id() << " finished waiting\n";
		}

		Process *p = ready.front();
		ready.pop();
		p->scheduler_dispatch();
		p->report(std::cout);
		int opt = rand()%3;
		std::cout << "OPT: ";
		switch(opt){
			case 0:{// exit
				std::cout << "EXIT\n";
				auto itr = std::find(all.begin(), all.end(), p);
				all.erase(itr);
				delete p;
				break;
			}
			case 1:{// event_wait
				std::cout << "EVENT_WAIT\n";
				p->event_wait();
				waiting.insert(p);
				break;
			}
			case 2:{// interrupt
				std::cout << "INTERRUPTTED\n";
				p->interrupt();
				ready.push(p);
				break;
			}
		}

		report(std::cout);
	}

}

int main(){
	Scheduler s;

	s.run(5);

	return 0;
}