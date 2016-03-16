//
// Created by yzchen on 16-3-4.
//

#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
#include "openglviewer.h"

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void spindisplay(){
    spin > 360 ? spin -= 360:spin += 2;
    glutPostRedisplay();
    usleep(10000);
}

void reshape(GLint xmax, GLint ymax){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(spin,0,0,1);
    draw(1);
    draw(2);
    draw(3);
    draw(4);
    draw(0);

//    glFlush();
    glutSwapBuffers();
}

void draw(int part){
    const int n = 80;
    const GLfloat R0 = 15.0f, R1 = 27.5f;
    const GLfloat Pi = 3.1415926536f;

    switch (part){
        case 0:     // draw center circle
            glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
            glBegin(GL_POLYGON);
            for(int i = 0; i < n; ++i)
                glVertex2f(R0 * cos(2 * Pi / n * i), R0 * sin(2 * Pi / n * i));
            glEnd();
            break;
        case 1:     // up
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            for (int j = 0; j <= n / 2; ++j) {
                glVertex2f(R1 * sin(2 * Pi / n * j), R1 * cos(2 * Pi / n * j) + 27.5);
            }
            glEnd();
            break;
        case 2:     // down
            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_POLYGON);
            for (int j = n / 2 ; j <= n; ++j) {
                glVertex2f(R1 * sin(2 * Pi / n * j), R1 * cos(2 * Pi / n * j) - 27.5);
            }
            glEnd();
            break;
        case 3:     // left
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_POLYGON);
            for (int j = 0; j <= n / 2; ++j) {
                glVertex2f(R1 * cos(2 * Pi / n * j) - 27.5, R1 * sin(2 * Pi / n * j));
            }
            glEnd();
            break;
        case 4:     // right
            glColor3f(1.0, 1.0, 0.0);
            glBegin(GL_POLYGON);
            for (int j = n / 2; j <= n; ++j) {
                glVertex2f(R1 * cos(2 * Pi / n * j) + 27.5, R1 * sin(2 * Pi / n * j));
            }
            glEnd();
            break;
        default:
            break;
    }
}

