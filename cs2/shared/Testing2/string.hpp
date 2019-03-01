#ifndef JM_NEWSTR_H_
#define JM_NEWSTR_H_

//File:        string.h   
//       
//Version:     1.0
//Date:        9/5/2013 - Current Version Kent State University

//Author:      Dr. J. Maletic
//
//Description: Class definition for a String.
//
//
//  Class: String 
//
//  Simple version with fixed sized array of char.  
//
//  Defines a character String data type with associated operators.
//  Examples:  String a;              //of capacity DEFAULT_STRING_CAPACITY
//
//  - Strings are indexed from 0 to capacity-1 of char.
//  - a = ""; assigns a to the empty String.


#include <iostream>
#include <cassert>

const int DEFAULT_STRING_CAPACITY = 256;

////////////////////////////////////////////////////
// CLASS INV: 0 <= length() < DEFAULT_STRING_CAPACITY  && 
//            str[length()] == 0
//            
class String {
public: 
            String        ();               
            String        (const char*); 
            String        (const char);  

    bool    operator<     (const String&)           const;
    
private:  
    char    str[DEFAULT_STRING_CAPACITY];  
};

std::istream& operator>>(std::istream&, String&);

bool    operator<      (const char*,   const String&);
bool    operator<      (const char,    const String&);

#endif

