/*
Hannah Russwurm
Oct. 28, 2016
hrusswur@uwo.ca
250662242
The purpose of this program is to implement a wiremesh renderer and output a vase created by reading vertex points from a text file.
*/

#ifndef DRAW_H
#define DRAW_H

#include <GL/freeglut.h>

using namespace std;

vector<vector<vector<GLfloat>>> drawVase(vector<vector<GLfloat>> points, GLint degrees);

#endif