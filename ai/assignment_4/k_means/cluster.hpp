#ifndef AI_4_CLUSTER
#define AI_4_CLUSTER

#include "points.hpp"
#include "regression.hpp"

class Cluster{
private:
	Points members;
	Point centroid;
	double radius;

public:
	Cluster(){};
	Cluster(double r){radius = r;};

	void generate_random_centroid(double, double, double, double, int); //get init centroid provided range in max, min, x, y
	void recalculate_centroid();// recalculate centroid based on points in members
	void set_radius(double r){radius = r;};
	Points& get_members(){return members;};
	Point& get_centroid(){return centroid;};
	double get_radius(){return radius;};

	friend std::ostream& operator<<(std::ostream&, const Cluster&);


};

#endif