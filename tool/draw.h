#ifndef DRAW_H
#define DRAW_H

#include <windows.h>
#include <GL/glut.h>

void line(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat = 1);
void Hollow_Square(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat = 1);
void Solid_Square(GLfloat, GLfloat, GLfloat, GLfloat);
void checkerboard(GLfloat, GLfloat, GLfloat, GLfloat, int, int, GLfloat = 1);
void Counterclockwise_Degree_Rotation(GLfloat, GLfloat);

#endif
