/*
Hannah Russwurm
Oct. 28, 2016
The purpose of this program is to implement a wiremesh renderer and output a vase created by reading vertex points from a text file.
FileReader.cpp reads the points from the .txt file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <GL/glut.h>
#include <vector>
#include <stdlib.h>
#include <GL/glu.h>
#include "FileReader.h"
using namespace std;

//Constructor
FileReader::FileReader(string file)
{
	loadFile(file);
}

//This is where we actually read in all the points and store them in a vector of vectors. 
bool FileReader::loadFile(string file)
{
	ifstream myfile(file.c_str());
	stringstream stringstr;

	//Read our file
	if (myfile.is_open()) 
	{
		//Read in all of the points and store them in a string
		stringstr << myfile.rdbuf();
		string stringOfAllPoints = stringstr.str();
		//Close the file, we no longer need it
		myfile.close();

		size_t len = stringOfAllPoints.length();
		size_t position = 0;
		string::size_type sz;

		//while we're still within the file
		while (position < len) 
		{ 
			string pointString;
			vector<GLfloat> point;

			//while we're in the same line
			while (stringOfAllPoints.at(position) != '\n' && position < len) 
			{ 
				//while we're not at the end
				while (stringOfAllPoints[position] != '\n') 
				{
					//get all the real points and add them to our string
					pointString += stringOfAllPoints.at(position);
					if (stringOfAllPoints.at(position) == ' ')
					{
						point.push_back(stoi(pointString));
						pointString = "";
					}
					//increment our position
					position++;
				}
				//add point to our vector
				point.push_back(stoi(pointString));
			}
			//add point vector to our other vector 
			points.push_back(point);
			//increment our position
			position++;
		}
		return true;
	}
	
	//Throw an error if we cannot open the file
	if (myfile.fail())
	{
		cout << "Can't open this file" << endl;
		return false;
	}
}

//return the points when called on main
vector<vector<GLfloat>> FileReader::getPoints()
{
	return points;
}

FileReader::FileReader()
{

}

FileReader::~FileReader()
{

}
