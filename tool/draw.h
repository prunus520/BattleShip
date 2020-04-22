#ifndef DRAW_H
#define DRAW_H

#include <windows.h>
#include <GL/glut.h>

void line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat LineWidth = 1);
void Hollow_Square(GLfloat x1, GLfloat y1, GLfloat width, GLfloat height, GLfloat LineWidth = 1);
void Solid_Square(GLfloat x1, GLfloat y1, GLfloat width, GLfloat height);
void checkerboard(GLfloat x, GLfloat y, GLfloat width, GLfloat height, int width_cell, int height_cell, GLfloat LineWidth = 1);
void Counterclockwise_Degree_Rotation(GLfloat x, GLfloat y);

#endif
