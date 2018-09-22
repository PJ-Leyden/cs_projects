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
    String giveDay(){return day;};
    String giveMonth(){return month;};
    String giveYear(){return year;};

    void setDay(String dy){
        day = dy;
    };
    void setMonth(String mn){
        month = mn;
    };
    void setYear(String yr){
        year = yr;
    };
private:
    String  day, month, year;
    //int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
    Time() {};
    String giveHour(){return hour;};
    String giveMinute(){return minute;};
    String giveSecond(){return second;};

    void setHour(String hr){
        hour = hr;
    };
    void setMinute(String mn){
        minute = mn;
    };
    void setSecond(String sc){
        second = sc;
    };
  private:
    String     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
    LogEntry(){};
    LogEntry(String);
    String giveOriginal()const{return original;};
    String giveHost()const{return host;};
    int giveBytes()const{return number_of_bytes;};
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);
private:
    String  original;
    String  host;//vec[0]
    Date    dte;//vec[3]
    Time    tme;//vec[3]
    String  request;
    String  status;
    int  number_of_bytes;
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

