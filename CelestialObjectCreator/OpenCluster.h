/**
Brandon Erb
Header for class that class that adds celestial bodies to a desired size of space, distributed in an open cluster.
*/

#pragma once
#include "uniformDistribution.h" //Need for struct definition
#include <vector>
#include <stdlib.h>
#include <time.h>

#ifndef OPENCLUSTER_H
#define OPENCLUSTER_H

class OpenCluster
{
public:
	int numBodies;
	int sizeOfSpace;
	const double spacing = 0.8;
	const double binding = 8;

	OpenCluster();
	~OpenCluster();

	std::vector<Coords> Create();
	double Random(double distance);
};

#endif //OPENCLUSTER_H