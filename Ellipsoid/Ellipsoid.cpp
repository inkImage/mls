//
// Created by yzchen on 16-3-7.
//

#include <iostream>
#include <cmath>
#include "Ellipsoid.h"
#include "mousemove.h"

using namespace std;

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

void displayEllipsoid(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glLoadIdentity();

    double c = M_PI / 180.0;

//    gluLookAt(0.0, 3.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    LookAt();
    glColor3f(0.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    drawEllipsoid(0.0, 0.0, 0.0, 2.0, 1.0, 1.0);

    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height){
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawEllipsoid(GLfloat xx, GLfloat yy, GLfloat zz, GLfloat rx, GLfloat ry, GLfloat rz){
    double c = M_PI / 180;
    double x, y, z;
    for(int phi = -80;phi <= 80;phi += 20){
        double phir = c * phi;
        double phir20 = c * (phi + 20);

        glBegin(GL_QUAD_STRIP);
        for(double theta = -180.0; theta <= 180; theta += 20){
            double thetar = c * theta;

            x = xx + rx * sin(thetar) * cos(phir);
            y = yy + ry * cos(thetar) * cos(phir);
            z = zz + rz * sin(phir);
            glVertex3d(x,y,z);

            x = xx + rx * sin(thetar) * cos(phir20);
            y = yy + ry * cos(thetar) * cos(phir20);
            z = zz + rz * sin(phir20);
            glVertex3d(x,y,z);
        }
        glEnd;
    }

    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(0.0, 0.0, 1.0);
    double c80 = c * 80;
    z = zz + rz * sin(c80);
    for(double theta = -180.0; theta <= 180;theta += 20) {
        double thetar = c * theta;
        x = xx + rx * sin(thetar) * cos(c80);
        y = yy + ry * cos(thetar) * cos(c80);

        glVertex3d(x,y,z);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(0.0, 0.0, -1.0);
    c80 = c * (-80);
    z = zz + rz * sin(c80);
    for(double theta = -180.0; theta <= 180;theta += 20) {
        double thetar = c * theta;
        x = xx + rx * sin(thetar) * cos(c80);
        y = yy + ry * cos(thetar) * cos(c80);

        glVertex3d(x,y,z);
    }
    glEnd();

}
