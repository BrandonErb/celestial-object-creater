/**
Brandon Erb
Class that class that adds celestial bodies to a desired size of space, distributed in an open cluster.
*/
#pragma once
#include "OpenCluster.h"

using namespace std;

OpenCluster::OpenCluster()
{
}


OpenCluster::~OpenCluster()
{
}

std::vector<Coords> OpenCluster::Create()
{
	vector<Coords> locations;

	time_t currentTime = time(NULL);
	time_t currentDay = time(0);
	int startOfDay;
	tm *now = gmtime(&currentDay);
	startOfDay = ((now->tm_hour * 60) + (now->tm_min * 60)) + now->tm_sec; //seconds in a day 86400
	srand(startOfDay); //seeding expected to be repeated daily

	for (int i = 1; locations.size() < numBodies; i++)
	{
		if (locations.size() != 0)
		{
			bool tooClose = false; //flag for deciding if an object is too close;
			int index = 0;
			double x = Random(binding * 2) - binding;
			double y = Random(binding * 2) - binding;
			double z = Random(binding * 2) - binding;
			Coords displacement = { x,y,z };

			//Check if object is inside the boundries
			do
			{
				//Select Random Object
				index = Random(locations.size());
				if (locations[index].x < sizeOfSpace && locations[index].x > 0 && locations[index].y < sizeOfSpace && locations[index].y > 0 && locations[index].z < sizeOfSpace && locations[index].z > 0)
				{
					break;
				}

			} while (0);

			Coords newBody = { locations[index].x + displacement.x, locations[index].y + displacement.y, locations[index].z + displacement.z };

			//Verify that object is not too close to another
			for (int j = 0; j < locations.size(); ++j)
			{
				Coords verifyDistance = locations[j];

				if (fabs(newBody.x - verifyDistance.x) < spacing && fabs(newBody.y - verifyDistance.y) < spacing && fabs(newBody.z - verifyDistance.z) < spacing)
				{
					tooClose = true;
				}
			}

			//After all checks add object or try again
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
			double x = Random(sizeOfSpace);
			double y = Random(sizeOfSpace);
			double z = Random(sizeOfSpace);
			Coords firstBody = { x,y,z };
			locations.push_back(firstBody);
		}
	}

	return locations;
}


double OpenCluster::Random(double distance)
{
	return (rand() % (int)distance);
}

