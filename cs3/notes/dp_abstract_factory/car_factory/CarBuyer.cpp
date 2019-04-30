// needed for lab
// Mikhail Nesterenko
// 3/14/2016

#include <iostream>
#include <vector>
#include <cstdlib>
#include "CarFactory.h"

using std::vector;
using std::cout; using std::endl;

class CarLot{
public:
   CarLot();
   Car *testDriveCar(){return car4sale_;}

   // if a car is bought, requests a new one
   Car *buyCar(){ 
      Car *bought = car4sale_;
      car4sale_ = 
        factories_[rand()%factories_.size()]->requestCar();
      return bought;
   }
		     
private:
   Car *car4sale_; // single car for sale at the lot
   vector<CarFactory *> factories_;
};


CarLot::CarLot(){
   // creates 2 Ford factories and 2 Toyota factories 
   factories_.push_back(new FordFactory());   
   factories_.push_back(new ToyotaFactory());
   factories_.push_back(new FordFactory());
   factories_.push_back(new ToyotaFactory());

   // gets the first car for sale
   car4sale_ = factories_[rand() % factories_.size()] -> requestCar();
}



CarLot *carLotPtr = nullptr; // global pointer instantiation

// test-drives a car
// buys it if Toyota
void toyotaLover(int id){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();

   Car *toBuy = carLotPtr -> testDriveCar(); 

   cout << "Buyer " << id << endl;
   cout << "test driving " 
	<< toBuy->getMake() << " "
	<< toBuy->getModel();

   if (toBuy->getMake() == "Toyota"){
      cout << " love it! buying it!" << endl;
      carLotPtr -> buyCar();
   } else
      cout << " did not like it!" << endl;
}

// test-drives a car
// buys it if Ford
void fordLover(int id){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();

   Car *toBuy = carLotPtr -> testDriveCar();
   
   cout << "Buyer " << id << endl;
   cout << "test driving "
	<< toBuy->getMake() << " "
        << toBuy->getModel();
   
   if (toBuy->getMake() == "Ford"){
      cout << " love it! buying it!" << endl;
      carLotPtr -> buyCar();
   } else
      cout << " did not like it!" << endl;
}



int main() {
   srand(time(nullptr));

   const int numBuyers=10;
   for(int i=0; i < numBuyers; ++i)
      if(rand()% 2 == 0)
	 toyotaLover(i);
      else
	 fordLover(i);
  
}
