// implements command history 
// (multiple undos)
// demonstrates command pattern
// Mikhail Nesterenko
// 11/22/2014

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::vector; using std::string;
using std::cout; using std::cin; using std::endl;

// receiver
class Document {
public:

   Document(const vector <string> 
	    & data={}): data_(data){}

   void insert(int line, 
	       const string &str) {
      int index = line-1;
      if (index <= data_.size())
	 data_.insert
	    (data_.begin() + index, str); 
      else
	 cout << "line out of range" << 
	    endl; 
   }

   string remove(int line) {
      int index = line-1;
      string deletedLine="";
      if(index < data_.size()){
	 deletedLine = data_[index];
	 data_.erase(data_.begin() + index); 
      }else
	 cout << "line out of range" << endl; 
      return deletedLine;
   } 

   void show() {
      for(int i = 0; i < data_.size(); ++i)
	 cout << i + 1 << ". " << 
	    data_[i] << endl; 
   }

private:
   vector<string> data_; 
}; 

// abstract command
class Command{
public:
   Command(Document *doc) : doc_(doc){}
   virtual void execute() = 0; 
   virtual void unexecute() = 0; 
   virtual ~Command(){}
protected:
   Document *doc_; 
}; 

// two concrete commands
class InsertCommand : public Command {
public:
   InsertCommand(Document *doc, int line, 
		 const string &str): 
      Command(doc), line_(line), 
      str_(str) {}
   void execute() {
      doc_->insert(line_, str_);}
   void unexecute() {doc_->remove(line_);}
private:
   int line_; 
   string str_; 
}; 


class EraseCommand : public Command {
public:
   EraseCommand(Document *doc, int line): 
      Command(doc), line_(line), str_("") {}
   void execute() {str_ = doc_->remove(line_);}
   void unexecute() {doc_-> insert(line_, str_);}
private:
   int line_;
   string str_;
};

// client
class DocumentWithHistory{
public:
   DocumentWithHistory(const vector<string> & 
		       text={}) : doc_(text){}

   void insert(int line, string str) {
      Command *com = new InsertCommand(&doc_, line, str); 
      com->execute(); 
      doneCommands_.push(com); 
   }

   void erase(int line){
      Command *com = new EraseCommand(&doc_, line);
      com->execute();
      doneCommands_.push(com);
   }

   void undo() {
      if(doneCommands_.size() != 0) {
	 Command *com = 
	    doneCommands_.top(); 
	 doneCommands_.pop(); 
	 com->unexecute();
	 delete com; // don't forget to delete command
      }else
	 cout << "no commands to undo" << endl; 
   }

   void show() {doc_.show();}

private:
   std::stack<Command*> doneCommands_; 
   Document doc_;
}; 

// invoker
int main() {
   DocumentWithHistory his({
	 "Lorem Ipsum is simply dummy text of the printing and typesetting",
	 "industry. Lorem Ipsum has been the industry's standard dummy text",
	 "ever since the 1500s, when an unknown printer took a galley of",
	 "type and scrambled it to make a type specimen book. It has",
	 "survived five centuries."}); 

   int line; string str; char option;

   do{
      his.show(); 
      cout << endl;

      cout << "Enter option (i)nsert line, (e)rase line, (u)ndo last command: ";
      cin >> option; 

      switch(option) {
      case 'i':
	 cout << "line number to insert: "; 
	 cin >> line; 
	 cout << "line to insert: "; 
	 cin.get();
	 getline(cin, str); 
	 his.insert(line, str); 
	 break;
 
      case 'e':
	 cout << "line number to remove: ";
	 cin >> line;
	 his.erase(line);
	 break;

      case 'u':
	 his.undo(); 
	 break; 
      }

   }while(option == 'i' || option == 'e' || option == 'u');
}
