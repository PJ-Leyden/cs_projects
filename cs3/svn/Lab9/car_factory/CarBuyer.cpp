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
   CarLot();   //Car *testDriveCar(){return car4sale_;}

   // if a car is bought, requests a new one
   Car* buyCar(){ 
      Car* bought = &car4sale_[next];
      car4sale_[next] = *(factories_[rand()%factories_.size()]->requestCar());
      return bought;
   }

   Car* nextCar(){
      ++next;
      if(next == LOT_SIZE)next = 0;
      Car* result = &car4sale_[next];
      return result;
   }

   void print(){
      std::cout << "Current Lot: " << next << '\n';
      for(int i = 0; i < LOT_SIZE; ++i){
         std::cout << car4sale_[i].getMake() << " ";
         std::cout << car4sale_[i].getModel() << '\n';
      }
      std::cout << '\n';
   }

   int lotSize(){ return LOT_SIZE; }
		     
private:
   static const  int           LOT_SIZE = 10;
          Car                  car4sale_[LOT_SIZE]; //array of cars for sale
          vector<CarFactory*>  factories_;
   static int                  next; 
};

int CarLot::next = -1;


CarLot::CarLot(){
   // creates 2 Ford factories and 2 Toyota factories 
   factories_.push_back(new FordFactory());   
   factories_.push_back(new ToyotaFactory());
   factories_.push_back(new FordFactory());
   factories_.push_back(new ToyotaFactory());

   // set the lot with random cars
   for(int i = 0; i < LOT_SIZE; ++i){
      car4sale_[i] = *(factories_[rand() % factories_.size()] -> requestCar());
   }
}



CarLot *carLotPtr = nullptr; // global pointer instantiation

// test-drives a car
// buys it if Toyota
void toyotaLover(int id){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();

   //Car *toBuy = carLotPtr -> testDriveCar(); 

   for(int i = 0; i < carLotPtr->lotSize(); ++i){
      Car* toBuy = carLotPtr->nextCar();
      cout << "Buyer " << id << endl;
      cout << "test driving " 
	  << toBuy->getMake() << " "
	  << toBuy->getModel();

      if (toBuy->getMake() == "Toyota"){
         cout << " love it! buying it!" << endl;
         carLotPtr -> buyCar();
         carLotPtr->print();
         break;
      } else
         cout << " did not like it!" << endl;
   }
}

// test-drives a car
// buys it if Ford
void fordLover(int id){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();

   //Car *toBuy = carLotPtr -> testDriveCar(); 

   for(int i = 0; i < carLotPtr->lotSize(); ++i){
      Car* toBuy = carLotPtr->nextCar();
      cout << "Buyer " << id << endl;
      cout << "test driving " 
     << toBuy->getMake() << " "
     << toBuy->getModel();

      if (toBuy->getMake() == "Ford"){
         cout << " love it! buying it!" << endl;
         carLotPtr -> buyCar();
         carLotPtr->print();
         break;
      } else
         cout << " did not like it!" << endl;
   }
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
