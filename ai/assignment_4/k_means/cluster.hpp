#ifndef AI_4_CLUSTER
#define AI_4_CLUSTER

#include "points.hpp"

class Cluster{
private:
	Points members;
	std::pair<double, double> centroid;
	double radius;

public:
	Cluster(){};
	Cluster(double r){radius = r;};

	bool generate_random_centroid(double, double, double, double); //get init centroid provided range in max, min, x, y
	bool recalculate_centroid();// recalculate centroid based on points in members
	bool add_point(std::pair<double, double>); // add point to members
	bool remove_point(std::pair<double, double>); // remove point from members
	Points& get_members();
	std::pair<double, double> get_centroid();

	friend std::ostream& operator<<(std::ostream&, const Cluster&);


}

#endif