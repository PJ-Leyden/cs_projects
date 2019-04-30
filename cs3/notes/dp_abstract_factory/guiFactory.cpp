// GUI (for Unix and Windows) coded using Abstract Factory
// Mikhail Nesterenko, lifted from "Design Patterns Explained Simply"
// 7/14/2014

#include <iostream>

using std::cout;

class Widget {  // abstract product
public:
   virtual void draw() = 0;
};

// concrete products
class UnixButton : public Widget {
public:
   void draw() { cout << "UnixButton\n"; }
};
class UnixMenu : public Widget {
public:
   void draw() { cout << "UnixMenu\n"; }
};

class WindowsButton : public Widget {
public:
   void draw() { cout << "WindowsButton\n"; }
};

class WindowsMenu : public Widget {
public:
   void draw() { cout << "WindowsMenu\n"; }
};


class Factory {  // abstract factory
public:
   // factory methods
   virtual Widget* create_button() = 0;
   virtual Widget* create_menu() = 0;
};

// two concerte factories
class UnixFactory : public Factory {
public:
   Widget* create_button() { return new UnixButton; }
   Widget* create_menu()   { return new UnixMenu; }
};

class WindowsFactory : public Factory {
public:
   Widget* create_button() { return new WindowsButton; }
   Widget* create_menu()   { return new WindowsMenu; }
};

Factory* factory;

// architecture-independent client code
void display_window_one() {
   Widget* w[] = { 
      factory->create_button(),
      factory->create_menu() 
   };
   w[0]->draw();  
   w[1]->draw();
}

void display_window_two() {
   Widget* w[] = { 
      factory->create_menu(),
      factory->create_button(), 
      factory->create_button()
   };
   w[0]->draw();  
   w[1]->draw();
   w[2]->draw();
}


#define UNIX // pick one architecture

int main() {

   // architecture-dependent client code
   // initalizing factory
#ifdef UNIX
   factory = new UnixFactory;
#else // WINDOWS
   factory = new WindowsFactory;
#endif

   
   // architecture-independent client code

   Widget* w = factory->create_button();
   w->draw();

   display_window_one();
   display_window_two();
}
