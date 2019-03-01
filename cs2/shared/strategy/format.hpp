////////////////////////////////////////////////////////////////
// Strategy pattern - Inheritance and virtuals
//
// Define a set of algorithms, encapsulate them, and make them interchangable.
// Stategy pattern lets teh algorithm vary independent of client.
// Captures the abstraction in an interface by burying the details in
//  derived classes.
//
// Read in text file and format it as left, right, or center justified.
//
// UML diagram at http://www.cs.kent.edu/~jmaletic/CS23001/strategy.html
//
#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <iostream>
#include <fstream>
#include <string>


////////////////////////////////////////////////////////////////
// A simple formating object. 
// Abstract Class - Interface/Strategy object
// 
class format {
public:
            format (int w): width(w) {};
    virtual ~format() {};
    void    output () {
                std::string line, word;
                std::ifstream inFile("quote.txt");
                
                inFile >> word;
                line = word;
                while (inFile >> word) {
                    if (line.length() + word.length() + 1 > width){
                        justify(line);
                        line = "";
                    }
                    if (line == "") line = word;
                    else line = line + " " + word;
                }
                justify(line);
                line = "";
                inFile.close();
            };
protected:
    unsigned int  width;
private:
    virtual void justify(const std::string&) = 0;  //Algorithm
};

////////////////////////////////////////////////////////////////
// Strategy Left
//
class LeftJustify: public format {
public:
    LeftJustify(int w): format(w) {};
private:
    virtual void justify(const std::string& line) {
        std::cout << line << std::endl;
    };
};


////////////////////////////////////////////////////////////////
//Strategy Right
//
class RightJustify: public format {
public:
    RightJustify(int w): format(w) {};
private:
    virtual void justify(const std::string& line) {
        for (unsigned int i=0; i < width - line.length(); ++i)
            std::cout << " ";
        std::cout << line << std::endl;
    };
};


////////////////////////////////////////////////////////////////
//Strategy Center
//
class CenterJustify: public format {
public:
    CenterJustify(int w): format(w) {};
private:
    virtual void justify(const std::string& line) {
        for (unsigned int i=0; i < (width - line.length())/2; ++i)
            std::cout << " ";
        std::cout << line << std::endl;
    };
};




#endif

