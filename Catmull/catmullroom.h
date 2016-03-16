#ifndef CATMULLROOM_H
#define CATMULLROOM_H

#include <Eigen/Dense>
#include <GL/glut.h>
#include <iostream>

using namespace std;

struct Point{
    GLfloat x;
    GLfloat y;
};

using namespace Eigen;

void init();
void reshape(int w, int h);
void display();

void computeCoff(Point p0, Point p1, Point p2, Point p3);
void drawVertex(GLfloat x,GLfloat y);
void draw(GLfloat t, GLfloat step);

#endif // CATMULLROOM_H
