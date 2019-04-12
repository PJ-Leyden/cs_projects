// drink class to be used in Coffee Shack lab
// Mikhail Nesterenko
// 11/15/2016

#include <string>
#include <vector>

enum class DrinkType {small, medium, large};

class Drink{
public:
   Drink(DrinkType type=small, double price=0):
                 type_(type), price_(price){}
   virtual int getPrice() const;
   virtual std::string getName() const;
private: 
   double price_;
   DrinkType type_;
};

class Coffee : public Drink {
public:
	int           getPrice()       const override;
	std::string   getName()        const override;
	std::string   getSize()        const;
	void          print_toppings() const;

	friend Coffee order_coffee();

private:
	std::string name_;
	std::vector<char> toppings_;
};
