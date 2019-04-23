/*
File: documenter.cpp
Author: P.J. Leyden
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::vector; using std::string;
using std::cout; using std::cin; using std::endl;

//Document Base
//=============================================================
class Document {
public:
	Document(vector <string> data={}): data_(data){}

	void insert(int line, const string &str) {
		int index = line-1;
		if (index <= data_.size()+1)
			data_.insert(data_.begin()+index, str); 
		else
			cout << "line out of range" << endl; 
	}

	string remove(int line) {
		int index = line-1;
		string deletedLine="";
		if(index < data_.size()){
			deletedLine = data_[index];
			data_.erase(data_.begin() + index); 
		}else{
			cout << "line out of range" << endl; 
		}
		return deletedLine;
   	} 

	void show() {
		for(int i = 0; i < data_.size(); ++i)
			cout << i + 1 << ". " << data_[i] << endl; 
	}
protected:
   vector<string> data_; 
}; 

//Command
//=============================================================
class Command{
public:
	Command(Document *doc) : doc_(doc){}
	virtual void execute() = 0; 
	virtual void unexecute() = 0; 
	virtual void print() = 0;
	virtual ~Command(){}
	virtual Command* clone() const = 0;
protected:
	Document *doc_; 
};

//Two concrete commands
//=============================================================
class InsertCommand : public Command {
public:
	InsertCommand(Document *doc, int line, const string &str): 
		Command(doc), line_(line), str_(str) {}


	void execute() {
		doc_->insert(line_, str_);
	}

	void unexecute() {doc_->remove(line_);}

	void print() {
		cout << "\tInsert:\n";
		cout << "\tLine Number: " << line_ << '\n';
		cout << "\tString Inserted: " << str_ << '\n';
	}

	Command* clone() const{
		return new InsertCommand(doc_, line_, str_);
	}
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

	void print(){
		cout << "\tErased:\n";
		cout << "\tLine Number: " << line_ << '\n';
		cout << "\tString Erased: " << str_ << '\n';
	}
	Command* clone()const {
		return new EraseCommand(doc_, line_);
	}
private:
	int line_;
	string str_;
};
//=============================================================

class SaveState;

class DocWithHistory: public Document{
public:
	DocWithHistory(const vector<string> & 
			   text={}) : doc_(text){}

	~DocWithHistory(){
		Command *ptr;
		while(!doneCommands_.empty()){
			ptr = doneCommands_.top();
			doneCommands_.pop();
			delete ptr;
		}
	}

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
			Command *com = doneCommands_.top(); 
			doneCommands_.pop(); 
			com->unexecute();
			delete com; // don't forget to delete command
		}else{
			cout << "No commands to undo." << endl; 
		}
	}

	void history(){
		std::stack<Command*> temp;
		int i = 0;
		while(!doneCommands_.empty()){
			++i;
			Command *t = doneCommands_.top();
			doneCommands_.pop();
			cout << i << ":\n";
			t->print();
			cout << '\n';
			temp.push(t);
		}
		while(!temp.empty()){
			Command *t = temp.top();
			temp.pop();
			doneCommands_.push(t);
		}
	}

	void redo(int num){
		Command *t;
		std::stack<Command*> temp;
		for(int i = 0; i < num - 1; ++i){
			t = doneCommands_.top();
			doneCommands_.pop();
			temp.push(t);
		}
		t = doneCommands_.top()->clone();
		t->execute();
		for(int i = 0; i < num - 1; ++i){
			doneCommands_.push(temp.top());
			temp.pop();
		}
		doneCommands_.push(t);
	}

	void show() {doc_.show();}

	SaveState* createSaveState() const;  
	void 	   rollBack(SaveState*);
private:
	std::stack<Command*> doneCommands_; 
	Document doc_;
};

//Memento
class SaveState{
public:
	SaveState(const DocWithHistory& doc): doc_(doc){}
	const DocWithHistory& getState()const{return doc_;}
private:
	DocWithHistory doc_;
};

SaveState* DocWithHistory::createSaveState() const{
	return new SaveState(*this);
}

void DocWithHistory::rollBack(SaveState *mem){
	*this = mem->getState();
}




int main(){
	DocWithHistory dh({
	 "Lorem Ipsum is simply dummy text of the printing and typesetting",
	 "industry. Lorem Ipsum has been the industry's standard dummy text",
	 "ever since the 1500s, when an unknown printer took a galley of",
	 "type and scrambled it to make a type specimen book. It has",
	 "survived five centuries."
	});

	char option;
	SaveState *save;

	do{
		dh.show();
		cout << "\n*** Menu ***\n";
		cout << "i: Insert Line\n";
		cout << "e: Erase Line\n";
		cout << "u: Undo Last Command\n";
		cout << "c: Make Checkpoint\n";
		cout << "b: Rollback\n";
		cout << "h: History\n";
		cout << "r: Redo\n";
		cout << "q: Quit\n";
		cout << '\n';
		cout << "\tEnter option: ";
		cin >> option;
		std::cout << '\n';

		switch(option){
			case 'i':{
				int line;
				string str;
				cout << "Enter line number: ";
				cin >> line;
				cout << "Enter line:\n";
				cin.get();
				std::getline(cin, str);
				dh.insert(line, str);
				break;
			}
			case 'e':{
				int line;
				cout << "Enter line number: ";
				cin >> line;
				dh.erase(line);
				break;
			}
			case 'u':{
				dh.undo();
				break;
			}
			case 'c':{
				save = dh.createSaveState();
				break;
			}
			case 'b':{
				dh.rollBack(save);
				break;
			}
			case 'h':{
				dh.history();
				break;
			}
			case 'r':{
				int hist_num;
				cout << "Enter history number of command to redo: ";
				cin >> hist_num;
				dh.redo(hist_num);
				break;
			}
		}
		cout << "\n\n";
		//cout << "Press Enter...\n";
		//cin.get();

	}while(option != 'q');
	

	return 0;
}