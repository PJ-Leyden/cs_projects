// decorator pattern, pointer-based
// Mikhail Nesterenko, adapted from Pro C++
// 7/28/2015

#include <string>
#include <iostream>

using std::cout; using std::endl;
using std::string;

// component
class Paragraph{
public:
   Paragraph(const string& text =""): text_(text) {}
   virtual string getHTML() const { return text_; }
private:
   const string text_;
};

// first decorator
class BoldParagraph : public Paragraph {
public:
   BoldParagraph(const Paragraph* wrapped): 
      wrapped_(wrapped) {}
   string getHTML() const override {
      return "<b>" + wrapped_->getHTML() + "</b>";
   }
private:
  const Paragraph *wrapped_;
};


// second decorator
class ItalicParagraph : public Paragraph {
public:
   ItalicParagraph(const Paragraph* wrapped):
      wrapped_(wrapped) {}
   string getHTML() const override {
      return "<i>" + wrapped_->getHTML() + "</i>";
   }
private:
   const Paragraph *wrapped_;
};


int main(){
   Paragraph p("Hello, World!");
   Paragraph q("Good bye, World!");
   
   cout << p.getHTML() << endl;
   cout << q.getHTML() << endl;

   // illustrates per-object application of decoration
   BoldParagraph bp(&p);
   ItalicParagraph iq(&q);
   cout << bp.getHTML() << endl;
   cout << iq.getHTML() << endl;

   ItalicParagraph iiq(&iq);
   cout << iiq.getHTML() << endl;

   // complex decorators
   BoldParagraph bip(&iq); 
   cout << bip.getHTML() << endl;

   ItalicParagraph ibp(&bp); 
   cout << ibp.getHTML() << endl;

   // dynamic decorator
   cout << BoldParagraph(&p).getHTML() << endl;

  
   // dynamic complex decorator
   cout << BoldParagraph(&iq).getHTML() << endl;
   cout << ItalicParagraph(&bp).getHTML() << endl;

}
