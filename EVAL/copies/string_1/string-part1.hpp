//File:        string.hpp
//
//Date:        Fall 2016
//Author:      Dr. J. Maletic
//
//Description: Interface definition of String class for use with test oracle for Part 1.
//
//             String implementation for Project 2 Part 1
//             CS II.  Use this for testing student projects
//             along with test oracles.
//
//

#ifndef CS23001_P1_STRING_INTERFACE_HPP
#define CS23001_P1_STRING_INTERFACE_HPP

#include <iostream>

const int DEFAULT_STRING_CAPACITY = 256; //Or what ever number is specified by the assignment.

class String {
public:
    String        ();
    String        (char);
    String        (const char[]);
    
    char&   operator[]    (int);
    char    operator[]    (int)                     const;
    int     capacity      ()                        const;
    int     length        ()                        const;
    bool    operator==    (const String&)           const;
    bool    operator<     (const String&)           const;
    String  operator+     (const String&)           const;

    friend std::istream& operator>>(std::istream&, String&);
    friend std::ostream& operator<<(std::ostream&, const String&);

private:
    char str[DEFAULT_STRING_CAPACITY];
};


String  operator+       (const char[],  const String&);
String  operator+       (char,          const String&);
bool    operator==      (const char[],  const String&);
bool    operator==      (char,          const String&);
bool    operator<       (const char[],  const String&);
bool    operator<       (char,          const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);

#endif

