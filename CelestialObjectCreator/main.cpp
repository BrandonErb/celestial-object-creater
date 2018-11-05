/**
Brandon Erb
Description: Application that populates objects in a 3 dimensional space 
*/

#include <windows.h> 
#include "uniformdistribution.h"
#include "OpenCluster.h"
#include "OpenGLDraw.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	UniformDistribution makeBodies;
	OpenCluster cluster;
	vector<Coords> locations;
	Coords output;
	int numBodies = 100;
	int spaceSize = 100;

	//cout << "Enter number of celestial bodies: ";
	//cin >> numBodies;
	//cout << "Enter the size of space in light years: ";
	//cin >> spaceSize;

	makeBodies.numBodies = numBodies;
	makeBodies.sizeOfSpace = spaceSize;
	locations = makeBodies.Create();

	/*cluster.numBodies = numBodies;
	cluster.sizeOfSpace = spaceSize;
	locations = cluster.Create();*/

	OpenGLDraw Draw(locations, spaceSize);

	for (int i = 0; i < locations.size(); i++)
	{
		output = locations[i];
		cout << "[" << output.x << "]" << "[" << output.y << "]" << "[" << output.z << "]\n";
	}

	Draw.OpenWindow(argc, argv);

	return 0;
}