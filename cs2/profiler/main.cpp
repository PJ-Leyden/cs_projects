/*
 *  main.cpp
 *  Profiler
 *
 *  Created by Jonathan Maletic.
 *  Copyright 2016 Kent State University. All rights reserved.
 *
 *  Requires main.cpp first, followed by other files.
 *
 *  Modified by:
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "ASTree.hpp"
#include "profile.hpp"


//
// Reads a srcML file into an internal data structure.
// Then prints out the data structure.

//============================================================================

void testCopyDest(srcML actual){
    srcML test(actual);

    std::cout << actual << '\n';

    std::cout << "//===================================================\n";

    std::cout << test << '\n';
}

//============================================================================

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Input file(s) are required." << std::endl;
        std::cerr << "       The main must be the first argument followed by ";
        std::cerr << "any other .cpp files.  For example:" << std::endl;
        std::cerr << "profiler main.cpp.xml file1.cpp.xml file2.cpp.xml";
        std::cerr << std::endl << std::endl;
        return(1);
    }
    
    srcML                     code;           //Source code to be profiled.
    std::vector<std::string>  files;          //List of file names (no .xml)
    std::vector<std::string>  profileNames;   //List of profile names
    
    for (int i = 1; i < argc; ++i) {
        std::string filename = argv[i];
        files.push_back(filename);
        filename = filename.substr(0, filename.find(".xml"));      //Remove .xml
        std::replace(filename.begin(), filename.end(), '.', '_');  //. => _
        profileNames.push_back(filename);
    }
    
    std::ifstream inFile(files[0].c_str());    //Read in the main.
    inFile >> code;
    inFile.close();

    code.mainHeader(profileNames, files);             //Add in main header info
    code.mainReport(profileNames);             //Add in the report
    code.funcCount(profileNames[0]);           //Count funciton invocations
    code.lineCount(profileNames[0]);           //Count line invocations
    
    std::string outFileName = "p-" + files[0];
    outFileName = outFileName.substr(0, outFileName.find(".xml"));
    std::ofstream outFile(outFileName.c_str());
    outFile << code << std::endl;
    outFile.close();

    for (unsigned i = 1; i < files.size(); ++i) {  //Read rest of the files.
        inFile.open(files[i].c_str());
        inFile >> code;
        inFile.close();
        
        code.fileHeader(profileNames[i]);       //Add in file header info
        code.funcCount(profileNames[i]);        //Count funciton invocations
        code.lineCount(profileNames[i]);        //Count line invocations
        
        outFileName = "p-" + files[i];
        outFileName = outFileName.substr(0, outFileName.find(".xml"));
        outFile.open(outFileName.c_str());
        outFile << code << std::endl;
        outFile.close();
    }

    testCopyDest(code);

	return 0;
}
