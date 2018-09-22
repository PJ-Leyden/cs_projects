/*
 *  ASTree.cpp
 *  Abstract Syntax Tree
 *
 *  Created by Jonathan Maletic
 *  Copyright 2016 Kent State University. All rights reserved.
 *
 *  Modified by:
 *
 */

#include "ASTree.hpp"


/////////////////////////////////////////////////////////////////////
// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    tree = new AST(*(actual.tree));
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}


/////////////////////////////////////////////////////////////////////
// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    src.tree->print(out);
    return out;
}




/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::mainHeader(std::vector<std::string>& profileNames, std::vector<std::string>& files) {
    tree->mainHeader(profileNames, files);
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
//
void srcML::mainReport(std::vector<std::string>& profileNames) {
        tree->mainReport(profileNames);
}

/////////////////////////////////////////////////////////////////////
//  Inserts a filename.count() into each function body.
//
void srcML::funcCount(const std::string& profilename) {
    tree->funcCount(profilename);
}

/////////////////////////////////////////////////////////////////////
// Inserts a filename.count() for each statement.
//
void srcML::lineCount(const std::string& profilename) {
    tree->lineCount(profilename);
}

    


/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}






///
///  NOTE: Can implement destructor implemented in .h file or here.
///
/////////////////////////////////////////////////////////////////////
AST::~AST(){
    for(std::list<AST*>::const_iterator itr = child.begin(); itr != child.end(); ++itr){
        delete *itr;
    }
    //std::cerr << "Left Destr" << '\n';
}



/////////////////////////////////////////////////////////////////////
// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    nodeType = actual.nodeType;
    tag = actual.tag;
    closeTag = actual.closeTag;
    text = actual.text;
    for(std::list<AST*>::const_iterator itr = actual.child.begin(); itr != actual.child.end(); ++itr){
        child.push_back(new AST( **itr ));
    }
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for AST
//
void AST::swap(AST& b) {
    {
        nodes temp = b.nodeType;
        b.nodeType = nodeType;
        nodeType = temp;
    }
    {
        std::string temp = b.tag;
        b.tag = tag;
        tag = temp;
    }
    {
        std::string temp = b.closeTag;
        b.closeTag = closeTag;
        closeTag = temp;
    }
    {
        std::list<AST*> temp = child;
        child = b.child;
        b.child = temp;
    }
    {
        std::string temp = b.text;
        b.text = text;
        text = temp;
    }
}

/////////////////////////////////////////////////////////////////////
// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}

//AST& AST::operator=(AST&& rhs){

//}


/////////////////////////////////////////////////////////////////////
// Returns a pointer to child[i] where (child[i]->tag == tagName)
//
// IMPORTANT for part 3
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}



/////////////////////////////////////////////////////////////////////
// Returns the full name of a <name> node.
//
// IMPORTANT for part 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}




/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables in a main file.
//
void AST::mainHeader(std::vector<std::string>& profileNames, std::vector<std::string>& files) {

    //NEED TO IMPLEMENT
    //Skip down a couple lines.
    //For each file profile name, add a new node with a profile 
    // declaration.
    //Also, add in the profile declaration for functions and the
    //include for profile.hpp

    std::list<AST*>::iterator it = child.begin();
    bool foundInclude = false;
    while( (*it) -> tag != "function" ){
        ++it;
        foundInclude = true;
    }
    --it;
    child.insert(it, new AST(whitespace, "\n"));
    if(foundInclude){
        child.insert(it, new AST(token, "#include \"profile.hpp\"\n"));//takes what type it is... it is of type AST* so...
        for(size_t i = 0; i < profileNames.size(); ++i){
            child.insert( it, new AST(token, "profile " + profileNames[i] + "(\"" + files[i].substr(0, files[i].find(".xml")) + "\");\n") );
        }
    }
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables for non-main files
//
void AST::fileHeader(const std::string& profileName) {

    //NEED TO IMPLEMENT
    //Skip down a couple lines.
    //For each file profile name, add a new node with a profile 
    // extern declaration.
    //Also, add in the extern declaration for functions and the
    //include for profile.hpp
    
    std::list<AST*>::iterator it = child.begin();
    bool foundInclude = false;
    while( (*it) -> tag != "function" ){
        ++it;
        foundInclude = true;
    }
    --it;
    child.insert(it, new AST(whitespace, "\n"));
    if(foundInclude){
        child.insert(it, new AST(token, "#include \"profile.hpp\"\n"));//takes what type it is... it is of type AST* so...
        child.insert(it, new AST(token, "extern profile " + profileName + ";"));
    }
}

/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
// Assumes only one return at end of main body.
//
void AST::mainReport(std::vector<std::string>& profileNames) {
    std::cerr << "Start Report\n";
    //NEED TO IMPLEMENT
    //Find the function with name main and then start from the end.
    //Find the main - function with name of "main"
    //Then start from the end() of this function and iterate
    // backwards until you find a return stmt.   You'll want
    // to insert the report statements before this return.
    
    std::list<AST*>::iterator it = child.begin();
    bool foundMainFunc = false;
    std::list<AST*>::iterator innerIt;
    while(!foundMainFunc && it != child.end()){
        innerIt = (*it) -> child.begin();
        if(*innerIt){
            std::cerr <<"x"<< (*innerIt) -> tag <<"x"<< '\n';
            if((*innerIt) -> tag == "main"){
                foundMainFunc = true;
                it = innerIt;
            }
            else{
                ++it;
            }
        }
        else{
            ++it;
            continue;
        }
        
        
    }
    std::cerr << "found main\n";
    //it points at main function AST
    while((*it) -> tag == "block" && it != child.end()){
        ++it;
    }

    it = (*it) -> child.begin();

    while((*it) -> tag == "return" && it != child.end()){
        ++it;
    }

    for(size_t i = 0; i < profileNames.size(); ++i){
        child.insert(it, new AST(token, "std::cout << " + profileNames[i] + " << endl;\n"));
    }
    std::cerr << "Left Report\n";
}


/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each function is executed.
//  Assumes no nested functions.
//
void AST::funcCount(const std::string& profileName) {
    
    //NEED TO IMPLEMENT
    
    // for all children
    //     if child is a function, constructor, destructor
    //        Find the function name
    //        Find block and insert line as first line in block
    //

    std::list<AST*>::iterator it = child.begin();
    while(it != child.end()){
        if(it -> tag == "function"){
            std::list<AST*>::iterator i = it -> child;
            while(i != it -> child.end()){
                if(i -> tag == "block"){
                    std::list<AST*>::iterator last = i -> child;
                    (i -> child).insert(last, new AST(token, profileName + ".count(__LINE__, \"" + child.name + "\""))
                }
                ++i;
            }
        }
        ++it;
    }


}

/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each statement is executed.
//   No breaks, returns, throw etc.
//   Assumes all construts (for, while, if) have { }.
//
void AST::lineCount(const std::string& profileName) {
    
    //NEED TO IMPLEMENT
    
    // Recursively check for expr_stmt and call
    
    
}


/////////////////////////////////////////////////////////////////////
// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end(); ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}


/////////////////////////////////////////////////////////////////////
// Print an AST 
// REQUIRES: indent >= 0
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin();
         i != child.end(); ++i) {
        switch ((*i)->nodeType) {
            case category:
                (*i)->print(out);
                break;
            case token:
                out << (*i)->text;
                break;
            case whitespace:
                out << (*i)->text;
                break;
        }
    }
    return out;
}

    
    
    

/////////////////////////////////////////////////////////////////////
// Utilities
//

// IMPORTANT for part 3
bool isStopTag(std::string tag) {
    if (tag == "decl_stmt"            ) return true;
    if (tag == "argument_list"        ) return true;
    if (tag == "init"                 ) return true;
    if (tag == "condition"            ) return true;
    if (tag == "cpp:include"          ) return true;
    if (tag == "macro"                ) return true;
    if (tag == "comment type\"block\"") return true;
    if (tag == "comment type\"line\"" ) return true;
    return false;
}

//For reading

/////////////////////////////////////////////////////////////////////
// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
//
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
//
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">");}
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<");}
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&");}
    return s;
}


/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
//
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

