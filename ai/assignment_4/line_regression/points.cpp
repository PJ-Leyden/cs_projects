#include "points.hpp"

bool Point::operator==(const Point& p){
	if(p.x == x && p.y == y){
		return true;
	}
	return false;
}

void Points::generate_random_points(int num, double maxX, double minX, double maxY, double minY){
	srand(time(NULL));

	for(int i = 0; i < num; i++){
		int x = (rand() % (int)(maxX - minX)) + minX;
		int y = (rand() % (int)(maxY - minY)) + minY;
		Point temp(x, y);
		if(check(temp) == -1){
			pts.push_back(temp);
			size++;
		}else{
			--i;
		}
	}
}

int Points::check(const Point& p){
	for(int i = 0; i < size; i++){
		if(pts[i] == p){
			return i;
		}
	}
	return -1;
}

bool Points::add_point(const Point& p){
	if(check(p) == -1){
		pts.push_back(p);
		size++;
		return true;
	}
	return false;
}

bool Points::remove_point(const Point& p){
	int indx = check(p);
	if(indx != -1){
		for(int i = indx; i < size - 1; i++){
			pts[indx] = pts[indx + 1];
			pts.pop_back();
			return true;
		}
	}
	return false;
}

Point& Points::operator[](int x){
	return pts[x];
}

const Point& Points::operator[](int x)const{
	return pts[x];
}

std::ostream& operator<<(std::ostream& out, const Points& points){
	int count = 1;
	for(Point p : points.pts){
		out <<"P" << count << ":\t(" << p.x << "," << p.y << ")\n";
		count++;
	}
	return out;
}
