// adding/removing lines of text, demos Memento Design Pattern
// Mikhail Nesterenko
// 11/22/2014

#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::string;
using std::cout; using std::cin; using std::endl;

// originator
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

   void remove(int line) {
      int index = line-1;
      if(index < data_.size())
	 data_.erase(data_.begin()+index); 
      else
	 cout << "line out of range" << endl; 
   } 

   void show() {
      for(int i = 0; i < data_.size(); ++i)
	 cout << i + 1 << ". " << data_[i] << endl; 
   }


   class Memento *createMemento() const;  
   void rollBack(class Memento *); 

private:
   vector<string> data_; 
}; 

class Memento {
public:
   Memento(const Document& doc): doc_(doc) {}
   const Document& getState() const {return doc_;}  
private:
   const Document doc_;
};
 
Memento *Document::createMemento() const{
   // copying the Document itself
   return new Memento(*this); 
}

void Document::rollBack(Memento *mem){
   *this = mem->getState();  // copying back
}

// client and caretaker
int main() {

   Document doc({
         "Lorem Ipsum is simply dummy text of the printing and typesetting",
         "industry. Lorem Ipsum has been the industry's standard dummy text",
         "ever since the 1500s, when an unknown printer took a galley of",
	 "type and scrambled it to make a type specimen book. It has",
	 "survived five centuries."});

   int line; string str; char option;

   Memento *checkpoint = nullptr;

   do{
      doc.show();
      cout << endl;

      cout << "Enter option (i)nsert line, (e)rase line, (c)heckpoint, (r)ollback: ";
      cin >> option;

      switch(option) {
      case 'i':
         cout << "line number to insert: ";
         cin >> line;
         cout << "line to insert: ";
	 cin.get();
         getline(cin, str);
         doc.insert(line, str);
         break;
      case 'e':
         cout << "line number to remove: ";
         cin >> line;
         doc.remove(line);
         break;
      case 'c':
	 checkpoint = doc.createMemento();
	 break;
      case 'r':
	 if (checkpoint != nullptr){
	    doc.rollBack(checkpoint);
	    delete checkpoint;
	 }
         break;
      }
   }while(option == 'i' || option == 'e' || 
	  option == 'c' || option == 'r');
}
