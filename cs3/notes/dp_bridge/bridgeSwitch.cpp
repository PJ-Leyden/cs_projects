// switch/appliance demonstrates Bridge Design Pattern,
// remote control contols TV, handle switich controls vacuum,
// the control bridges over Switch--> Appliance,
// Mikhail Nesterenko
// 2/11/2014

#include <iostream>
#include <string>

using std::string; using std::cout; using std::endl;

// abstract body
class Appliance{
public:
   Appliance(const string& name):name_(name){}
   virtual void run() =0;
   virtual void stop() =0;
   virtual string getStatus() =0;
   void report() { cout << name_ << " is 
                   " << getStatus() << endl;}
   virtual ~Appliance(){}
private: 
   string name_;
};

// concrete body one
class Vacuum: public Appliance{
public:
   Vacuum(const string& name):Appliance(name){}
   void run()  {status_ = "vacuuming carpet";}
   void stop() {status_ = "standing in the closet";}
   string getStatus(){return status_;}
private:
   string status_;
};

// concrete body two
class TV: public Appliance{
public:
   TV(const string &name):Appliance(name){}
   void run() {state_= "showing"; channel_="news";}
   void stop() {state_ = "blank";}
   string getStatus(){return state_ + ' ' + (state_ != "blank" ? channel_ : "");}
private:
   string state_;
   string channel_;
};

// abstract handle
class Switch{
public:
   Switch(const string &name, Appliance *controls): 
      name_(name), controls_(controls){}
   void turnOn()
   {cout << name_ << " turns on" << endl;  controls_->run();}
   void turnOff()
   {cout << name_ << " turns off" << endl;  controls_->stop();}
   virtual ~Switch(){}
protected:
   Appliance *controls_;
private:
   string name_;
};

// concrete handle one
class RemoteControl: public Switch{
public:
   RemoteControl(const string &name, Appliance *controls): Switch(name, controls){}
};

// concrete handle two
class HandleSwitch: public Switch{
public:
   HandleSwitch(const string &name, Appliance *controls): Switch(name, controls){}
};

int main(){

   // declaration, bodies
   Appliance *tv = new TV("Bedroom TV"); 
   Appliance *vac = new Vacuum("Hoover WindMill");

   // declaration, handles
   Switch *redSwitch = new HandleSwitch("red switch", vac);
   Switch *remote = new RemoteControl("remote control", tv); // tv has two handles
   Switch *blueButton = new HandleSwitch("blue button", tv);

   // vacuum operation
   redSwitch -> turnOn();    vac->report();
   redSwitch -> turnOff();   vac->report();

   cout << endl;
   
   // tv operation
   remote -> turnOn();         tv -> report();
   remote -> turnOff();        tv -> report();

   blueButton -> turnOn();     tv -> report();
   blueButton -> turnOff();    tv -> report();


}
