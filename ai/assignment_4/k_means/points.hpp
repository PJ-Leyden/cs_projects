#ifndef AI_4_POINTS
#define AI_4_POINTS

#include <iostream>
#include <utility>
#include <list>
#include <cstdlib>
#include <ctime>

struct Point{
	double x;
	double y;
};

class Points{
private:
	std::list<Point> pts;
	int size; // number of points in pts

public:
	Points(){size = 0;};

	bool generate_random_points(int, double, double, double, double);
	bool check(const Point&);//check for point in pts
	bool add_point(const Point&);
	bool remove_point(const Point&);
	int size(){return size;};

	friend std::ostream& operator<<(std::ostream&, const Points&);

};

#endif