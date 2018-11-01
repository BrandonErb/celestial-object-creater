/**
Brandon Erb
Class that class that adds celestial bodies to a desired size of space, randomly distributed.
*/
#pragma once
#include "uniformDistribution.h"
using namespace std;


//UniformDistribution::UniformDistribution(int pNumBodies, int pSizeOfSpace)
//{
//	numBodies = pNumBodies;
//	sizeOfSpace = pSizeOfSpace;
//}

UniformDistribution::UniformDistribution()
{

}

//Destructor
UniformDistribution::~UniformDistribution(void)
{

}

std::vector<Coords> UniformDistribution::Create()
{
	vector<Coords> locations;

	time_t currentTime = time(NULL);
	time_t currentDay = time(0);
	int startOfDay;
	tm *now = gmtime(&currentDay);
	startOfDay = ((now->tm_hour * 60) + (now->tm_min * 60)) + now->tm_sec; //seconds in a day 86400
	srand(startOfDay);

	for (int i = 0; i < numBodies; ++i)
	{
		bool tooClose = false; //flag for deciding if an object is too close;
		double x = Random(sizeOfSpace);
		double y = Random(sizeOfSpace);
		double z = Random(sizeOfSpace);
		Coords newBody = { x,y,z };
		
		if (locations.size() != 0)
		{
			for (int j = 0; j < locations.size(); ++j)
			{
				Coords verifyDistance = locations[j];

				if (fabs(newBody.x - verifyDistance.x) < spacing && fabs(newBody.y - verifyDistance.y) < spacing && fabs(newBody.z - verifyDistance.z) < spacing)
				{
					tooClose = true;
				}
			}

			if (tooClose == false)
			{
				locations.push_back(newBody);
			}
			else
			{
				i--; //object was too close to another try inserting another one
			}
		}
		else //add first entry
		{
			locations.push_back(newBody);
		}		
	}
	
	return locations;
}


double UniformDistribution::Random(double distance)
{
	return (rand() % (int)distance);
}
