#include "drink.hpp"

class Customer{
private:
	std::string name_;
public:
	Customer(std::string n = ""):
		name_(n){};

	void notify(std::string);

	bool operator==(const Customer &org){return name_ == org.name_;}
};

enum Level {JuniorBarista, SeniorBarista, Manager};

class Barista{
private:
	std::vector<Customer> patrons_;
	std::vector<Coffee> orders_;
	Level lvl_;
	Barista *super_;

public:
	Barista(Level l = JuniorBarista, Barista *b = nullptr):
		lvl_(l), super_(b){};

	void notify(Coffee&);

	void add_patron(Customer, Level);
	bool remove_patron(Customer, Level);
	void add_drink(Coffee, Level);
	bool remove_drink(Coffee, Level);

	void order_up();

	void print_order_complete(Coffee&);
};

class Coffee_Shop{
private:
	Barista *bar_;
public:
	Coffee_Shop();

	Coffee buy_drink();
	void   run_shop();

};