//
// Created by yzchen on 16-3-7.
//

#ifndef ELLIPSOID_ELLIPSOID_H
#define ELLIPSOID_ELLIPSOID_H

#include <GL/glut.h>

void init();

void displayEllipsoid();

void reshape(int width, int height);

void drawEllipsoid(GLfloat xx, GLfloat yy, GLfloat zz, GLfloat rx, GLfloat ry, GLfloat rz);

void Mouse(int button, int state, int x, int y);

void onMouseMove(int x, int y);

#endif //ELLIPSOID_ELLIPSOID_H
