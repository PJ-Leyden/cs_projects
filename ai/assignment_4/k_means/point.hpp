#ifndef AI_4_POINT
#define AI_4_POINT

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

	void generate_random_point(double, double, double, double);

};

#endif