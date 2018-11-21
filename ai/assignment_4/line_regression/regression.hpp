#ifndef AI_4_REGRESSION
#define AI_4_REGRESSION

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

double mean(std::list<double> set){
	double answer = 0;
	for(double i : set){
		answer += i;
	}
	answer /= set.size();
	return answer;
};

double best_fit_slope(const Points& points){
	double numerator = 0;
	double denominator = 0;
	std::list<double> x;
	std::list<double> y;
	for(int i = 0; i < points.get_size(); i++){
		x.push_back(points[i].x);
		y.push_back(points[i].y);
	}
	double x_mean = mean(x);
	double y_mean = mean(y);

	for(int i = 0; i < points.get_size(); i++){
		numerator += (points[i].x - x_mean)*(points[i].y - y_mean);
		denominator += pow((points[i].x - x_mean), 2);
	}

	return numerator/denominator;
};

double best_fit_y_int(const Points& points){
	std::list<double> x;
	std::list<double> y;
	for(int i = 0; i < points.get_size(); i++){
		x.push_back(points[i].x);
		y.push_back(points[i].y);
	}
	double x_mean = mean(x);
	double y_mean = mean(y);

	double slope = best_fit_slope(points);

	return (y_mean - (slope * x_mean)); 
};

double guess_y(double x, const Points& points){
	double slope = best_fit_slope(points);
	double y_int = best_fit_y_int(points);
	return ((slope * x) + y_int);
};





#endif 