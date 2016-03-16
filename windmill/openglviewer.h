//
// Created by yzchen on 16-3-4.
//

#ifndef TESTOPENGL_OPENGLVIEWER_H
#define TESTOPENGL_OPENGLVIEWER_H

static GLfloat spin = 0;

void init();

void spindisplay();

void reshape(GLint xmax, GLint ymax);

void display();

void draw(int part);

#endif //TESTOPENGL_OPENGLVIEWER_H
