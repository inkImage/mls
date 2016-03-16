//
// Created by yzchen on 16-3-12.
//

#ifndef ELLIPSOID_MOUSEMOVE_H
#define ELLIPSOID_MOUSEMOVE_H

#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

// record the state of mouse
extern GLboolean mouserdown, mouseldown, mousemdown;

// when a mouse-key is pressed, record current mouse position
extern GLint mousex, mousey;

extern GLfloat center[3];   // center position
extern GLfloat eye[3];      // eye's position

extern GLfloat yrotate; /// angle between y-axis and look direction
extern GLfloat xrotate; /// angle between x-axis and look direction
extern GLfloat celength;/// lenght between center and eye

extern GLfloat mSpee; /// center move speed
extern GLfloat rSpeed; /// rotate speed
extern GLfloat lSpeed; /// reserved

// calculate the eye position according to center position and angle,length
void CalEyePostion();

// center moves
void MoveBackward();              // center 点沿视线方向水平向后移动

void MoveForward();

// visual angle rotates
void RotateLeft();

void RotateRight();

void RotateUp();

void RotateDown();

// CALLBACK func for keyboard presses
void KeyFunc(unsigned char key, int x, int y);

// CALLBACK func for mouse kicks
void MouseFunc(int button, int state, int x, int y);

// CALLBACK func for mouse motions
void MouseMotion(int x, int y);

void LookAt();            // 调用 gluLookAt(), 主要嫌直接调用要每次都写好几个参数。。

#endif //ELLIPSOID_MOUSEMOVE_H
