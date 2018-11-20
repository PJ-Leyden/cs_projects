#include "cluster.hpp"
#include "points.hpp"

#include <string>

int main(){//hard or soft clustering? (hard hopefully)

	//choose ranges
	double maxX = 50; minX = -50;
	double maxY = 50; minY = -50;

	//generate random points
	Points all_points;
	all_points.generate_random_points(60, maxX, minX, maxY, minY);

	//decide on number of clusters
	int num_clusters = 4;

	//create clusters and outlier set
	Cluster clusters[num_clusters];
	Points outliers;

	//decide threshold
	double radius = 4.5;

	//generate random centroid for clusters
	for(int i = 0; i < num_clusters; i++){
		clusters[i].set_radius(radius); // set radius of all clusters
		clusters[i].generate_random_centroid(maxX, minX, maxY, minY);
	}

	//{
		//determine membership
			//cycle through all_points and check dist to centroid of all clusters.
			//assign to private member variable members of lowest distance. 

		//re calc cluster centoid
	//} end when no point moves. 
	

}