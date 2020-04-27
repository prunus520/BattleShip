#ifndef DRAW_H
#define DRAW_H

#include <windows.h>
#include "../library/include/GL/glut.h"

void line(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat = 1);
void Hollow_Square(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat = 1);
void Solid_Square(GLfloat, GLfloat, GLfloat, GLfloat);
void checkerboard(GLfloat, GLfloat, GLfloat, GLfloat, int, int, GLfloat = 1);
void counterclockwiseDegreeRotation(GLfloat, GLfloat);

#endif
