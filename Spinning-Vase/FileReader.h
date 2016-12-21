/*
Hannah Russwurm
Oct. 28, 2016
The purpose of this program is to implement a wiremesh renderer and output a vase created by reading vertex points from a text file.
*/

#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class FileReader
{
private:
	vector<vector<GLfloat>> points;
public:
	FileReader::FileReader();
	FileReader::~FileReader();
	FileReader::FileReader(string file);
	bool FileReader::loadFile(string file);
	vector<vector<GLfloat>> FileReader::getPoints();
};

#endif
