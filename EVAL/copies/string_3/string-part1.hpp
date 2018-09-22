//File:        string.hpp
//
//Date:        Fall 2016
//Author:      Dr. J. Maletic
//Modified by: P.J. Leyden
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
    String        ();                                                //done//
    String        (char);                                            //done//
    String        (const char[]);                                    //done//
                                                                     ////////
    char&   operator[]    (int);                                     //done//
    char    operator[]    (int)                     const;           //done//
    int     capacity      ()                        const;           //done//
    int     length        ()                        const;           //done//
    bool    operator==    (const String&)           const;           //done//
    bool    operator<     (const String&)           const;           //done//
    String  operator+     (const String&)           const;           //done//
    String  substr        (int, int)                const;
    int     findstr       (const String&)           const;
    int     findchar      (char)                    const;
                                                                     ////////
    friend std::istream& operator>>(std::istream&, String&);         //done//
    friend std::ostream& operator<<(std::ostream&, const String&);   //done//

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

