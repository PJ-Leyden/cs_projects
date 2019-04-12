#include "coffee_shop.hpp"

void Coffee_Shop::buy_drink(){
	Coffee myCoffee = order_coffee();

	std::cout << myCoffee.getName() << ", your " << myCoffee.getSize();
	std::cout << "with ";
	myCoffee.print_toppings();
	std::cout << " is ready. It will be " << myCoffee.getPrice() << ", please.\n";
}
