#include "coffee_shop.hpp"


void Customer::notify(std::string n){
	if(n == name_){
		std::cout << name_ << " colleted there drink.\n";
	}
}

void Barista::notify(Coffee &c){
	print_order_complete(c);
	for(auto& cust : patrons_){
		cust.notify(c.getName());
	}
}

void Barista::add_patron(Customer c, Level l){
	if(l == lvl_ || super_ == nullptr){
		patrons_.push_back(c);
	}else{
		super_->add_patron(c, l);
	}
}

bool Barista::remove_patron(Customer c, Level l){
	if(l == lvl_ || super_ == nullptr){
		auto ptr = std::find(patrons_.begin(), patrons_.end(), c);
		if(ptr != patrons_.end()){
			patrons_.erase(ptr);
			return true;
		}
		return false;
	}else{
		return super_->remove_patron(c, l);
	}
}

void Barista::add_drink(Coffee c, Level l){
	if(l == lvl_ || super_ == nullptr){
		std::cout << "Drink being prepared by ";
		switch(lvl_){
			case JuniorBarista:
				std::cout << "a Junior Barista.\n";
				break;
			case SeniorBarista:
				std::cout << "a Senior Barista.\n";
				break;
			case Manager:
				std::cout << "a Manager.\n";
				break;
		}
		orders_.push_back(c);
	}else{
		super_->add_drink(c, l);
	}
}

bool Barista::remove_drink(Coffee c, Level l){
	if(l == lvl_ || super_ == nullptr){
		auto ptr = std::find(orders_.begin(), orders_.end(), c);
		if(ptr != orders_.end()){
			orders_.erase(ptr);
			return true;
		}
		return false;
	}else{
		return super_->remove_drink(c, l);
	}
}

void Barista::order_up(){
	if(!orders_.empty()){
		notify(*(orders_.begin()));
		remove_drink(*(orders_.begin()), lvl_);

	}else if(super_ != nullptr){
		super_->order_up();
	}
}

void Barista::print_order_complete(Coffee &c){
	std::cout << c.getName() << ", your " << c.getSize();
	std::cout << " with ";
	c.print_toppings();
	std::cout << " is ready. It will be " << c.getPrice() << "$, please.\n";
}

Coffee_Shop::Coffee_Shop(){
	bar_ = new Barista(JuniorBarista, new Barista(SeniorBarista, new Barista(Manager)));
}

Coffee Coffee_Shop::buy_drink(){
	Coffee myCoffee;
	myCoffee.order_coffee();
	return myCoffee;
}

void Coffee_Shop::run_shop(){
	char repeat;
	do{

		std::cout << "Order? [y/n] ";
		std::cin >> repeat;
		if(repeat != 'n'){
			Coffee c = buy_drink();
			Level drink_level;

			if(c.getLevel() == "low"){
				drink_level = JuniorBarista;
			}else if(c.getLevel() == "mid"){
				drink_level = SeniorBarista;
			}else{
				drink_level = Manager;
			}

			bar_->add_patron(Customer(c.getName()), drink_level);
			bar_->add_drink(c, drink_level);
		}
		if(rand()%2 && repeat != 'n'){
			bar_->order_up();
		}

	}while(repeat != 'n');
}

