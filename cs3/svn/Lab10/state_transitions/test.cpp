#include "process.hpp"

int main(){
	Process myproc;

	myproc.report(std::cout); // NEW

	myproc.admitted();

	myproc.report(std::cout); // READY

	myproc.exit();

	myproc.report(std::cout); // READY

	myproc.scheduler_dispatch();

	myproc.report(std::cout); // RUNNING

	myproc.interrupt();

	myproc.report(std::cout); // READY

	myproc.scheduler_dispatch();

	myproc.report(std::cout); // RUNNING

	myproc.exit();

	myproc.report(std::cout); // TERMINATED

	Process myproc2;

	myproc2.report(std::cout); // NEW

	myproc2.admitted();

	myproc2.report(std::cout); // READY

	myproc2.exit();

	myproc2.report(std::cout); // READY

	myproc2.scheduler_dispatch();

	myproc2.report(std::cout); // RUNNING

	myproc2.interrupt();

	myproc2.report(std::cout); // READY

	myproc2.scheduler_dispatch();

	myproc2.report(std::cout); // RUNNING

	myproc2.exit();

	myproc2.report(std::cout); // TERMINATED

	return 0;
}