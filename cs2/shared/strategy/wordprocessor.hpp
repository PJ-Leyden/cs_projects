////////////////////////////////////////////////////////////////
// Strategy pattern - Inheritance and virtuals
//
// Read in text file and format it as left, right, or center justified.
//
// UML diagram at http://www.cs.kent.edu/~jmaletic/CS23001/strategy.html
//
#ifndef WORDPRO_HPP
#define WORDPRO_HPP

#include "format.hpp"

////////////////////////////////////////////////////////////////
// Client.
//
class wordProcessor {
public:
         wordProcessor        () : width(20) {};
    void selectFormatingOption() {  
            format *txt;
            txt = new LeftJustify(width);
            txt->output();
            delete txt;
            std::cout << "------------------" << std::endl;
            txt = new RightJustify(width);
            txt->output();
            delete txt;
            std::cout << "------------------" << std::endl;
            txt = new CenterJustify(width);
            txt->output();
            delete txt;
            std::cout << "------------------" << std::endl;

        };

private:
    int  width;
};

#endif

