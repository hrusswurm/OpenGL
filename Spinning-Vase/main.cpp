/*
Hannah Russwurm
Oct. 28, 2016
The purpose of this program is to implement a wiremesh renderer and output a vase created by reading vertex points from a text file. 
*/

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "FileReader.h"
#include "Draw.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else 
#include <GL/glut.h>
#endif
using namespace std;

//Initialize constants and variables
static const int SCREENDIMENSION = 640;
static const int WINDOWPOSITION = 100;
static const GLint DEGREES = 20;
GLfloat ambientColor[] = { 0.9f, 0.5f, 0.2f, 1.0f };
static GLfloat rotation = 0.0;
static FileReader * readFile = new FileReader("vase.txt");
vector<vector<GLfloat>> points = readFile->getPoints();

//Vase actually draws our case in 3D
vector<vector<vector<GLfloat>>> vase = drawVase(points, DEGREES);

//This is where we render our mesh
void Mesh() 
{
	glPushMatrix();

	//Animate our vase on the screen 
	glRotatef(-97, 1.0, 0.0, -1.0);
	glRotatef(rotation, 0.0, 0.0, 1.0);
	rotation += 1;
	glTranslatef(0.0, 0.0, -20.0);

	//for each of the 180 profiles of points
	for (int profile = 0; profile < vase.size(); profile++)
	{
		//Begin our rendering
		glBegin(GL_TRIANGLE_STRIP);
		//go through every point
		for (int point = 0; point < vase[profile].size(); point++)
		{
			//create our verticies from points read in using the method described in the instructions
			glColor3f(0.5, 0.0, 0.5);
			glVertex3f(vase[profile][point][0], vase[profile][point][1], vase[profile][point][2]);
			glColor3f(0.5, 0.0, 0.5);
			glVertex3f(vase[(profile + 1) % vase.size()][point][0], vase[(profile + 1) % vase.size()][point][1], vase[(profile + 1) % vase.size()][point][2]);
			glVertex3f(vase[profile][(point) % vase[profile].size()][0], vase[profile][(point) % vase[profile].size()][1], vase[profile][(point) % vase[profile].size()][2]);
			glColor3f(0.5, 0.0, 0.5);
			glVertex3f(vase[(profile + 1) % vase.size()][(point) % vase[profile].size()][0], vase[(profile + 1) % vase.size()][(point) % vase[profile].size()][1], vase[(profile + 1) % vase.size()][(point) % vase[profile].size()][2]);
		}
		glEnd();
	}
	glPopMatrix();
}

//This method calls what to display, and displays it on the screen when called. 
void display() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//Set up our camera
	glOrtho(-25.0, 25.0, -25.0, 25.0, 0, 400);

	//Set up our light
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	GLfloat lightColor0[] = { 0.5f, 0.5f, 0.5f, 1.0f }; //Colour (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = { 4.0f, 10.0f, 8.0f, 1.0f }; //Light positioned at (4, 10, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	//Call mesh to draw our vase on the screen 
	Mesh(); 
	glutSwapBuffers();
}

//Initialize our window's properties
void init(void)
{
	//Black background
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//Enable our called methods to work
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals

	//Materialize our vase
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 150.0 };
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

//Main method
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	//Create our window, call it 'spinning vase'
	glutInitWindowSize(SCREENDIMENSION, SCREENDIMENSION);
	glutInitWindowPosition(WINDOWPOSITION, WINDOWPOSITION);
	glutCreateWindow("Spinning Vase");
	
	//Display our vase
	glutDisplayFunc(display);
	glutIdleFunc(display);
	init();

	//Continue looping
	glutMainLoop();
	return 0;
}
