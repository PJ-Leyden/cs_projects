#include "drink.hpp"

int Coffee::getPrice() const{
	return price_;
}

std::string Coffee::getName() const{
	return name_;
}

std::string Coffee::getSize() const{
	switch(type_){
		case small:
			return "small";
		case medium:
			return "medium";
		case large:
			return "large";
	}
}

Coffee order_coffee(){
	char size;
	char topping;
	std::cout << "Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee? ";
	std::cin >> size;
	std::cout << '\n';
	Coffee *coffee;
	switch(size){
		case 'l':
			coffee = new Coffee(large, 3.);
			break;
		case 'm':
			coffee = new Coffee(medium, 2.);
			break;
		case 's':
			coffee = new Coffee(small, 1.);
			break;
	}
	do{
		std::cout << "Would you like to add [s]prinkles, [c]aramel, milk [f]oam, [i]ce or [n]ot? ";
		std::cin >> topping;
		std::cout << '\n';
		switch(topping){
			case 's':
				coffee->toppings_.push_back(s);
				coffee->price_ += .5;
				break;

			case 'c':
				coffee->toppings_.push_back(c);
				coffee->price_ += .2;
				break;

			case 'f':
				coffee->toppings_.push_back(f);
				coffee->price_ += .4;
				break;

			case 'i':
				coffee->toppings_.push_back(i);
				coffee->price_ += .1;
				break;

			default:
				topping = 'n';
				break;
		}
	}while(topping != 'n');

	std::cout << "Can I get your name? ";
	std::cin >> coffee->name_;

	return *coffee;
}

void Coffee::print_toppings() const{
	for(char c : toppings){
		switch(c){
			case 's':
				std::cout << "sprinkles, ";
				break;

			case 'c':
				std::cout << "caramel, ";
				break;

			case 'f':
				std::cout << "milk foam, ";
				break;

			case 'i':
				std::cout << "ice, ";
				break;
		}
	}
}