#include "cluster.hpp"

void Cluster::generate_random_centroid(double maxX, double minX, double maxY, double minY, int cl){
	centroid = generate_random_point(maxX, minX, maxY, minY);
	centroid.cluster = cl;
}

void Cluster::recalculate_centroid(){
	if(members.get_size() == 0){
		return;
	}
	std::list<double> x;
	std::list<double> y;
	for(int i = 0; i < members.get_size(); i++){
		x.push_back(members[i].x);
		y.push_back(members[i].y);
	}
	double x_mean = Regression::mean(x);
	double y_mean = Regression::mean(y);

	centroid.x = x_mean;
	centroid.y = y_mean;
}

std::ostream& operator<<(std::ostream& out, const Cluster& c){
	out << "Centroid: " << c.centroid << '\n';
	out << c.members << '\n'; 
}