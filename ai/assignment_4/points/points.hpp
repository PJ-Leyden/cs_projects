#ifndef AI_4_POINTS
#define AI_4_POINTS

#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

struct Point{
	double x;
	double y;
	int cluster = -1;

	Point(){};
	Point(double ix, double iy){x = ix; y = iy;};
	bool operator==(const Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend double distance(const Point&, const Point&);
};

Point generate_random_point(double maxX, double minX, double maxY, double minY);

class Points{
private:
	std::vector<Point> pts;
	int size; // number of points in pts

public:
	Points(){size = 0;};

	void   generate_random_points(int, double maxX, double minX, double maxY, double minY);
	int    check                 (const Point&);//check for point in pts
	bool   add_point             (const Point&);
	bool   remove_point          (const Point&);
	int    get_size              ()const{return size;};
	Point& operator[]            (int);

	const Point& operator[]      (int)const;
	friend std::ostream& operator<<(std::ostream&, const Points&);

};

#endif