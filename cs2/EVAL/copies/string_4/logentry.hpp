#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
            Date() {};
private:
    String  day, month, year;
    //int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
            Time() {};
  private:
    String     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
        LogEntry(){};
        LogEntry(String);
        String& giveOriginal();
        friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  original;
    String  host;//vec[0]
    Date    date;//vec[3]
    Time    time;//vec[3]
    String  request;
    String  status;
    //int     number_of_bytes;
    String  number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);


#endif

