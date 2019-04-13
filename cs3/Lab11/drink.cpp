#include "drink.hpp"

double Coffee::getPrice() const{
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

void Coffee::order_coffee(){
	char size;
	char topping;
	std::cout << "Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee? ";
	std::cin >> size;
	std::cout << '\n';
	level_ = "low";
	switch(size){
		case 'l':
			type_ = large;
			price_ += 3.;
			break;
		case 'm':
			type_ = medium;
			price_ += 2.;
			break;
		case 's':
			type_ = small;
			price_ += 1.;
			break;
	}
	bool mid = false;
	bool high = false;
	do{
		std::cout << "Would you like to add [s]prinkles, [c]aramel, milk [f]oam, [i]ce or [n]ot? ";
		std::cin >> topping;
		std::cout << '\n';
		switch(topping){
			case 's':
				toppings_.push_back('s');
				price_ += .5;
				mid = true;
				break;

			case 'c':
				toppings_.push_back('c');
				price_ += .2;
				mid = true;
				break;

			case 'f':
				toppings_.push_back('f');
				price_ += .4;
				high = true;
				break;

			case 'i':
				toppings_.push_back('i');
				price_ += .1;
				mid = true;
				break;

			default:
				topping = 'n';
				break;
		}
	}while(topping != 'n');

	if(mid){
		level_ = "mid";
	}
	if(high){
		level_ = "high";
	}

	std::cout << "Can I get your name? ";
	std::cin >> name_;
}

void Coffee::print_toppings() const{
	for(char c : toppings_){
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

bool Coffee::operator==(const Coffee &org){
	return (toppings_ == org.toppings_ && name_ == org.name_);
}

std::string Coffee::getLevel() const { return level_; }