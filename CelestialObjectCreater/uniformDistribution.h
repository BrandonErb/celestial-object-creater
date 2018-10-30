/**
Brandon Erb
Header for class that adds celestial bodies to a desired size of space, randomly distributed.
*/
#pragma once
#include <vector>
#include <stdlib.h>
#include <time.h>

#ifndef UNIFORMDISTRIBUTION_H
#define UNIFORMDISTRIBUTION_H

//Struct for Coordinates
struct Coords
{
	double x, y, z;
};

class UniformDistribution
{
public:
	int numBodies;
	int sizeOfSpace;
	const double spacing = 0.8;

	//UniformDistribution(int numBodies, int sizeofSpace);
	UniformDistribution();

	~UniformDistribution(void);

	std::vector<Coords> Create();
	double Random(double distance);

};

#endif //UNIFORMDISTRIBUTION_H