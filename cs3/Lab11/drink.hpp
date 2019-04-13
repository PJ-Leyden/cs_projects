// drink class to be used in Coffee Shack lab
// Mikhail Nesterenko
// 11/15/2016

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

enum DrinkType {small, medium, large};

class Drink{
public:
   Drink(DrinkType type=small, double price=0):
        type_(type), price_(price){}

   virtual double      getPrice() const = 0;
   virtual std::string getName()  const = 0;
   virtual std::string getSize()  const = 0;

protected: 
	std::string name_;
    double      price_;
    DrinkType   type_;
};

class Coffee : public Drink {
public:
	Coffee(): 
		Drink(){}

	double        getPrice()       const override;
	std::string   getName()        const override;
	std::string   getSize()        const override;
	std::string   getLevel()       const;

	void          print_toppings() const;
	void          order_coffee();

	bool          operator==(const Coffee&);

private:
	std::vector<char> toppings_;
	std::string level_;
};
