#ifndef AI_4_POINTS
#define AI_4_POINTS

#include <iostream>
#include <utility>
#include <list>

class Point{
private:
	double x;
	double y;

public:
	Point(){};
	Point(double ix, double iy){
		x = ix;
		y = iy;
	};
	void set_x(double ix){x = ix};
	void set_y(double iy){y = iy};
	void set_point(double ix, double iy){
		x = ix;
		y = iy;
	};
	void get_x(){return x;};
	void get_y(){return y;};

};

class Points{
private:
	std::list<Point> pts;
	int size; // number of points in pts

public:
	Points(){size = 0;};

	bool generate_random_points(int, double, double, double, double);
	bool check(Point);//check for point in pts
	bool add_point(Point);
	bool remove_point(Point);
	int size(){return size;};

	friend std::ostream& operator<<(std::ostream&, const Points&);

};

#endif