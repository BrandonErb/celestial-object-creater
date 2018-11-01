#pragma once
#include <gl\glut.h>
#include <gl\GL.h>
#include <vector>
#include <windows.h>
#include "uniformDistribution.h" //Need for struct definition

#ifndef OPENGLDRAW_H
#define OPENGLDRAW_H

class OpenGLDraw
{
public:
	OpenGLDraw();
	OpenGLDraw(std::vector<Coords> coords, float size);
	~OpenGLDraw();
	void OpenWindow(int argc, char **argv);
	//void display();
};

#endif //OPENGLDRAW_H

