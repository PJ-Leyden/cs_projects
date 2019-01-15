#include "cluster.hpp"
#include <string>

bool determine_membership(Cluster*, Points&, int);

int main(){//hard or soft clustering? (hard hopefully)

	/*Points test;
	test.add_point(Point(2, 3));
	test.add_point(Point(5, 1));
	test.add_point(Point(6, 2));
	test.add_point(Point(4, 7));

	std::cout << test << '\n';
	test.remove_point(Point(2, 3));

	std::cout << test << '\n';
	test.remove_point(Point(2, 3));*/


	//choose ranges
	double maxX = 50, minX = -50;
	double maxY = 50, minY = -50;

	//generate random points
	Points all_points;
	all_points.generate_random_points(80, maxX, minX, maxY, minY);

	//decide on number of clusters
	int num_clusters = 6;

	//create clusters and outlier set
	Cluster clusters[num_clusters];
	Points outliers;

	//decide threshold
	double radius = 30;	

	//generate random centroid for clusters
	for(int i = 0; i < num_clusters; i++){
		clusters[i].set_radius(radius); // set radius of all clusters
		clusters[i].generate_random_centroid(maxX, minX, maxY, minY, i);
	}

	//std::cerr << "Here\n";
	int count = 0;

	bool loc_change = determine_membership(clusters, all_points, num_clusters);
	count++;

	while(loc_change){
		for(int i = 0; i < num_clusters; i++){
			clusters[i].recalculate_centroid();
		}

		loc_change = determine_membership(clusters, all_points, num_clusters);
		count++;
	}

	std::cout << all_points << std::endl;
	for(int i = 0; i < num_clusters; i++){
		std::cout << "Cluster " << i << '\n';
		std::cout << clusters[i]; 
	}
	std::cout << "Times run: " << count << '\n';
	//{
		//determine membership
			//cycle through all_points and check dist to centroid of all clusters.
			//assign to private member variable members of lowest distance. 

		//re calc cluster centoid
	//} end when no point moves. 
}

bool determine_membership(Cluster* c, Points& pts, int nc){
	bool changed_location = false;
	for(int i = 0; i < pts.get_size(); i++){ // for every point
		double shortest_dist = distance(c[0].get_centroid(), pts[i]); // set short dist
		int indx_of_cluster = 0; // set indx of cluster to put it in. We assume cluster 0
		for(int j = 1; j < nc; j++){ // for all other clusters besides the first
			double cur_dist = distance(c[j].get_centroid(), pts[i]); // calculate dist
			if(shortest_dist > cur_dist){ // if its shorter than current shortest
				shortest_dist = cur_dist; //change
				indx_of_cluster = j; // change
			}
		}

		if(shortest_dist <= c[indx_of_cluster].get_radius()){ // if the distance is in the radius
			if(pts[i].cluster != indx_of_cluster){// if it changed location
				if(pts[i].cluster != -1){//wasn't a no one
					c[pts[i].cluster].get_members().remove_point(pts[i]);// remove from old place
				}
				changed_location = true; // set change of location
				pts[i].cluster = indx_of_cluster; //set points cluster
			}

			c[indx_of_cluster].get_members().add_point(pts[i]); // add it
		}else{ // if the im not adding it to current cluster
			if(pts[i].cluster != -1){
				changed_location = true;
				c[pts[i].cluster].get_members().remove_point(pts[i]);
			}
			pts[i].cluster = -1;
		}
	}

	return changed_location;
}