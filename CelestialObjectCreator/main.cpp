/**
Brandon Erb
Description: Application that populates objects in a 3 dimensional space 
*/

#include <windows.h> 
#include "uniformdistribution.h"
#include "OpenCluster.h"
#include "OpenGLDraw.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char * argv[])
{
	UniformDistribution makeBodies;
	OpenCluster cluster;
	vector<Coords> locations;
	Coords output;
	int numBodies = 100; //test number
	int spaceSize = 100; //test number
	char type;

	cout << "Enter number of celestial bodies: ";
	cin >> numBodies;
	cout << "Enter the size of space in light years: ";
	cin >> spaceSize;
	cout << "Enter the type of distribution (u)niform or (c)lustered: ";
	cin >> type;

	switch (type) {
		case 'u':
			makeBodies.numBodies = numBodies;
			makeBodies.sizeOfSpace = spaceSize;
			locations = makeBodies.Create();
			break;
		case 'c':
			cluster.numBodies = numBodies;
			cluster.sizeOfSpace = spaceSize;
			locations = cluster.Create();
			break;
		default:
			cout << "Invalid input";
			return 1;
	}

	OpenGLDraw Draw(locations, spaceSize);

	for (int i = 0; i < locations.size(); i++)
	{
		output = locations[i];
		cout << "[" << output.x << "]" << "[" << output.y << "]" << "[" << output.z << "]\n";
	}

	Draw.OpenWindow(argc, argv);

	return 0;
}