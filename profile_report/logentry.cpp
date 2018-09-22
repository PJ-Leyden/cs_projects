

//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <cassert>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES: 
// ENSURES: 
//
LogEntry::LogEntry(String s){//disect each line, search till '\0', itterate with []
original = s;
std::vector<String> vec = s.split(' ');
{
	//===========================================
	std::cerr<<"vec size is: "<<vec.size()<<'\n';
	size_t indx = 0; 
	while(indx < vec.size()){
		std::cerr<<"vec["<<indx<<"] == "<<vec[indx]<<'\n';
		indx++;
	}
	//===========================================
}
assert(vec.size() == 10);
host = vec[0];
{//figure out date/time
	String temp = vec[3];
	//=====================
	std::vector<String> dateTime = temp.split(':');
	tme.setHour(dateTime[1]);
	tme.setMinute(dateTime[2]);
	tme.setSecond(dateTime[3]);
	{//the date
		std::vector<String> theDate = dateTime[0].split('/');
		String theDay = theDate[0];
		dte.setMonth(theDate[1]);
		dte.setYear(theDate[2]);
		dte.setDay(theDay[1] + theDay[2]);
	}
}
request = vec[5] + ' ' + vec[6] + ' ' + vec[7];
status = vec[8];
number_of_bytes = vec[9].toInt();
//std::cerr<<"Finished a LogEntry\n";
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
	{
    	/*std::vector<LogEntry> result;
    	String lgntry;
    	while(!in.eof()){
			in >> lgntry;
			std::cerr<<lgntry<<'\n';
			LogEntry temp(lgntry);
			result.push_back(temp);
		}
    	return result;*/
	}
	std::vector<LogEntry> result;
	while(in.eof()){
		String lgntry = "";
		char temp;
		std::cerr<<"Parse put together string == ";
		while(in.get(temp) && temp != '\n'){
			lgntry = lgntry + temp;
			std::cerr<<temp;
		}
		//std::cerr<<'\n';
		std::cerr<<"Here"<<'\n';
		if(in.eof()){
			break;
		}
		std::cerr<<"Parse == "<<lgntry<<'\n';
		LogEntry temp2(lgntry);
		result.push_back(temp2);
		//result.push_back(new LogEntry(lgntry));
		//delete temp2;
	}
	return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry>& temp) {
	for(size_t indx = 0; indx < temp.size(); indx++){
		out << temp[indx].giveOriginal()<<'\n';
	}
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& temp) {
	for(size_t indx = 0; indx < temp.size(); indx++){
		out << temp[indx].giveHost();
	}
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry>& temp) {
	int sze = temp.size();
	int result = 0;
	for(int i = 0; i < sze; i++){
		result += temp[i].giveBytes();
	}
	return result;
}
//========================================================