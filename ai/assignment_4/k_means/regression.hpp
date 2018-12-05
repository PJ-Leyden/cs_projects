#ifndef AI_4_REGRESSION
#define AI_4_REGRESSION

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include "points.hpp"

namespace Regression{

	double mean(std::list<double>);

	double best_fit_slope(const Points&);

	double best_fit_y_int(const Points&);

	double guess_y(double, const Points&);

}





#endif 