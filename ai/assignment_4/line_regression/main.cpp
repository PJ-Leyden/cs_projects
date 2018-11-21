#include "points.hpp"
#include "regression.hpp"
#include <iostream>

int main(){

	Points points;
	points.generate_random_points(50, 50, -50, 50, -50);

	std::cout << points;

	std::cout << guess_y(10, points) << std::endl;

	return 0;
}