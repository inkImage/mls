#include "catmullroom.h"

Vector4d coff;

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    Point p0 = {-5.9, -3.7}, p1 = {-0.1, -5.2}, p2 = {5.0, 6.9}, p3 = {9.3, 2.4};

    // 突出四个点
    glBegin(GL_POINTS);
    drawVertex(p0.x, p0.y);
    drawVertex(p1.x, p1.y);
    drawVertex(p2.x, p2.y);
    drawVertex(p3.x, p3.y);
    glEnd();

    computeCoff(p0, p1, p2, p3);

    GLfloat step = (p2.x - p1.x) / 100.0;
    for(GLfloat i = p1.x; i < p2.x; i += step){
        draw(i, step);
    }

    glFlush();
    glutSwapBuffers();
}

void computeCoff(Point p0, Point p1, Point p2, Point p3){
    Matrix4d X;
    GLfloat x0 = p0.x, x1 = p1.x, x2 = p2.x, x3 = p3.x;

    X(0, 0) = pow(x1, 3);
    X(0, 1) = pow(x1, 2);
    X(0, 2) = x1;
    X(0, 3) = 1;

    X(1, 0) = pow(x2, 3);
    X(1, 1) = pow(x2, 2);
    X(1, 2) = x2;
    X(1, 3) = 1;

    X(2, 0) = 3 * pow(x1, 2);
    X(2, 1) = 2 * x1;
    X(2, 2) = 1;
    X(2, 3) = 0;

    X(3, 0) = 3 * pow(x2, 2);
    X(3, 1) = 2 * x2;
    X(3, 2) = 1;
    X(3, 3) = 0;

    Vector4d Y;
    double y0 = p0.y, y1 = p1.y, y2 = p2.y, y3 = p3.y;

    Y[0] = y1;
    Y[1] = y2;
    Y[2] = (y2 - y0) / (2 * (x2 - x0));
    Y[3] = (y3 - y1) / (2 * (x3 - x1));

    coff = X.inverse() * Y;
}

void drawVertex(GLfloat x,GLfloat y){
    glVertex2f(x, y);
    glVertex2f(x-0.01, y);
    glVertex2f(x-0.01, y-0.01);
    glVertex2f(x, y);
    glVertex2f(x, y+0.01);
    glVertex2f(x+0.01, y);
    glVertex2f(x+0.01, y+0.01);
    glVertex2f(x, y+0.01);
    glVertex2f(x-0.01, y+0.01);
}

void draw(GLfloat t, GLfloat step){
    GLfloat px, py, pxn, pyn;

    px = t;
    py =(GLfloat)(coff(0) * pow(px, 3) + coff(1) * pow(px, 2) + coff(2) * px + coff(3));

    pxn = px + step;
    pyn = (GLfloat)(coff(0) * pow(pxn, 3) + coff(1) * pow(pxn, 2) + coff(2) * pxn + coff(3));

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(px, py);
    glVertex2f(pxn, pyn);
    glEnd();
}
