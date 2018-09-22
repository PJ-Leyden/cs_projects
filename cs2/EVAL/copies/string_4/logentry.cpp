

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
    assert(vec.size() == 10);
    host = vec[0];
    {//figure out date/time
    	String temp = vec[3];
    	//=====================
    	std::vector<String> dateTime = temp.split(':');
  		*this.time.hour = dateTime[1];
  		*this.time.minute = dateTime[2];
  		*this.time.second = dateTime[3];
  		String dte = dateTime[0]
  		{
  			std::vector<String> theDate = dte.split('/')
  			String theDay = theDate[0];
  			*this.date.month = theDate[1];
  			*this.date.year = theDate[2];
  			*this.date.day = theDay[1] + theDay[2];
  		}
    }
    request = vec[5] + ' ' + vec[6] + ' ' + vec[7];
    status = vec[8];
    number_of_bytes = vec[9];
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    String lgntry;
    while(!in.eof()){
    	lgntry << in;
    	LogEntry temp(lgntry);
    	result.push_back(temp);
	}
    return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry>& temp) {
    for(int indx = 0; indx < temp.size(); indx++)
    	out << temp[indx].original;

}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>&) {

}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry> &) {
    
    return 0;
}

String& LogEntry::giveOriginal(){
	return original;
}