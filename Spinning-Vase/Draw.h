/*
Hannah Russwurm
Oct. 28, 2016
The purpose of this program is to implement a wiremesh renderer and output a vase created by reading vertex points from a text file.
Draw.h is the header for Draw.cpp.
*/

#ifndef DRAW_H
#define DRAW_H

#include <GL/freeglut.h>

using namespace std;

vector<vector<vector<GLfloat>>> drawVase(vector<vector<GLfloat>> points, GLint degrees);

#endif
