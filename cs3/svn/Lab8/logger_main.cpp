#include "logger.hpp"

int main(){

	Logger* log = Logger::instance();

	log->report("First Log\n");

	//these should fail
	//Logger();               Private Ctor
	//Logger otherLog(*log);  Deleted Copy Ctor
	//*log = *log;            Deleted Assignment Operator

	return 0;
}