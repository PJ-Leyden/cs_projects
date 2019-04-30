// example GUI code needing to work with 
// two systems: Unix and Windows
// coded without Factory Pattern
// Mikhail Nesterenko

#include <iostream>
using std::cout;

#define UNIX

class Widget {
public:
   virtual void draw() = 0;
};

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


// client code

void display_window_one() {
   Widget* w[] = {
#ifdef UNIX
      new UnixButton,
      new UnixMenu 
#else // WINDOWS
      new WindowsButton,
      new WindowsMenu 
#endif
   };

   w[0]->draw();  
   w[1]->draw();
}

void display_window_two() {
#ifdef UNIX
   Widget* w[] = { 
      new UnixMenu,
      new UnixButton, 
      new UnixButton
   };
#else // WINDOWS
   Widget* w[] = { 
      new WindowsMenu,
      new WindowsButton, 
      new WindowsButton
   };
#endif
   w[0]->draw();  
   w[1]->draw();
   w[2]->draw();
}

int main() {
#ifdef UNIX
   Widget* w = new UnixButton;
#else // WINDOWS
   Widget* w = new WindowsButton;
#endif
   w->draw();
   display_window_one();
   display_window_two();
}
