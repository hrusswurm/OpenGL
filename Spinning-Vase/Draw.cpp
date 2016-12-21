/*
Hannah Russwurm
Oct. 28, 2016
The purpose of this program is to implement a wiremesh renderer and output a vase created by reading vertex points from a text file.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "Draw.h"
#define PI 3.14159265
using namespace std;
static const int FULLTURN = 360;
static const int NUMPROFILES = 180;

//Store our shape in a vector of vectors of vectors, haha.
vector<vector<vector<GLfloat>>> drawVase(vector<vector<GLfloat>> points, GLint degrees)
{
	//get our points
	vector<vector<vector<GLfloat>>> shape;
	vector<vector<GLfloat>> neighbourPoints = points;
	int profileCount = FULLTURN / degrees;

	//for all copies of points made from the points in vase.txt,
	for (int i = 0; i < profileCount - 1; i++) 
	{
		//for each individual point
		for (int point = 0; point < points.size(); point++) 
		{
			//Draw our vase with the points
			//Note, radians not degrees and that is why we have to multiply by Pi/180
			neighbourPoints[point][0] = (points[point][0] * cos(i*degrees*(PI / NUMPROFILES))) + (points[point][1] * -sin(i*degrees*(PI / NUMPROFILES)));
			neighbourPoints[point][1] = (points[point][0] * sin(i*degrees*(PI / NUMPROFILES))) + (points[point][1] * cos(i*degrees*(PI / NUMPROFILES)));
		}
		//Push back our profiles into another vector
		shape.push_back(neighbourPoints);
	}
	return shape;
}
