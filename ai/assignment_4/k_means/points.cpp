#include "points.hpp"

bool Point::operator==(const Point& p){
	if(p.x == x && p.y == y){
		return true;
	}
	return false;
}

double distance(const Point& p1, const Point& p2){
	double answer = sqrt( pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) );
	return answer;
}

std::ostream& operator<<(std::ostream& out, const Point& p){
	out << "(" << p.x << "," << p.y << ") Cluster: " << p.cluster;
	return out;
}

Point generate_random_point(double maxX, double minX, double maxY, double minY){
	int x = (rand() % (int)(maxX - minX)) + minX;
	int y = (rand() % (int)(maxY - minY)) + minY;
	Point temp(x, y);
	return temp;
}

void Points::generate_random_points(int num, double maxX, double minX, double maxY, double minY){
	srand(time(NULL));

	for(int i = 0; i < num; i++){
		Point temp = generate_random_point(maxX, minX, maxY, minY);
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
			pts[i] = pts[i + 1];
		}
		size--;
		pts.pop_back();
		return true;
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
	/*for(int i = 0; i < points.size; i+=4){
		for(int j = 0; j < 4; j++){
			if(i+j < points.size){
				out << "P" << i + j + 1 << points[i+j] << " \t";
			}
		}
		out << '\n';
	}*/
	for(int i = 0; i < points.size; i++){
		out << "P" << i + 1 << points[i] << "\n";
	}

	return out;
}
