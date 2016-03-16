#include <iostream>
#include <GL/glut.h>
#include "openglviewer.h"

using namespace std;

int main(int argc, char *argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(250, 150);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL Viewer");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(spindisplay);

    glutMainLoop();
    return 0;
}