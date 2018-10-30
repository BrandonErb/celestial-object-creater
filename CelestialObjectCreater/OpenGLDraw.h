#pragma once
#include <vector>
#include <windows.h>

//Struct for Coordinates
struct Coords
{
	double x, y, z;
};

class OpenGLDraw
{
public:
	OpenGLDraw();
	~OpenGLDraw();
	void OpenWindow(int argc, char **argv);
	//void display();
};

