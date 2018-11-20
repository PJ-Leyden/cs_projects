#include "points.hpp"
#include <iostream>

int main(){

	Points points;

	points.generate_random_points(50, 50, -50, 50, -50);

	std::cout << points;

	return 0;
}