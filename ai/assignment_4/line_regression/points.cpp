#include "points.hpp"

bool Points::generate_random_points(int num, double maxX, double minX, double maxY, double minY){
	srand(time(NULL));

	for(int i = 0; i < num; i++){
		int x = (rand() % (maxX - minX)) + minX;
		int y = (rand() % (maxY - minY)) + minY;
		Point temp; temp.x = x; temp.y = y;
		pts.push_back(temp);
		size++;
	}

	return true;
}

std::ostream& operator<<(std::ostream& out, const Points& points){
	for(int i = 0; i < points.size; i++){
		out << "P" << i + 1 << '\t' << points.pts[i] << '\n';
	}
	return out;
}