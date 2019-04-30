// demonstrates abstract factory pattern
// adapted from "Pro C++"
// Mikhail Nesterenko
// 7/16/2014

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "CarFactory.h"


using std::vector;
using std::cout; using std::endl;


CarFactory *getLeastBusyFactory(
         const vector<CarFactory*> &inFactories) {

   if (inFactories.size() == 0) return nullptr;

   auto bestSoFar = inFactories[0];
   
   for (size_t i = 1; i != inFactories.size(); ++i) {
      if (inFactories[i]->getNumCarsInProduction() < 
          bestSoFar->getNumCarsInProduction())
	 bestSoFar = inFactories[i];
   }
   return bestSoFar;
}

int main() {
   vector<CarFactory*> factories;
   
   srand(time(nullptr));

   // Create 3 Ford factories and 
   // 1 Toyota factory with random load. 
   factories.push_back(new FordFactory("Chicago, IL", 
				       rand()%4));   
   factories.push_back(new FordFactory("Dearborn, MI",
				       rand()%4));
   factories.push_back(new FordFactory("Louisville, KY", 
				       rand()%4));
   factories.push_back(new ToyotaFactory("Lafayette,IN", 
					 rand()%4));

   // Build 10 cars from the least busy factory.
   for (size_t i=0; i < 10; ++i) {
      CarFactory *currentFactory = 
	 getLeastBusyFactory(factories);
      Car *newCar = currentFactory->requestCar();
      cout << "Ordering " << newCar->getMake()  << " "
	   << newCar->getModel()
	   << " from " << currentFactory->getLocation() 
	   << endl;
   }
}
