#include <iostream>
#include "Ellipsoid.h"
#include "mousemove.h"

using namespace std;

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Ellipsoid");

    init();
    glutDisplayFunc(displayEllipsoid);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(KeyFunc);      //键盘按键
    glutMouseFunc(MouseFunc);       //鼠标按键
    glutMotionFunc(MouseMotion);    //鼠标移动
    glutMainLoop();

    return 0;
}