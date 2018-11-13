#ifndef AI_4_POINTS
#define AI_4_POINTS

#include <iostream>
#include <utility>
#include <list>

class Points{
private:
	std::list<std::pair<double, double>> pts;
	int size; // number of points in pts

public:
	Points(){size = 0;};

	bool generate_random_points(int num);
	bool add_point(std::pair<double, double>);
	bool remove_point(std::pair<double, double>);
	int size(){return size;};

	friend std::ostream& operator<<(std::ostream&, const Points&);

}

#endif