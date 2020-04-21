//			battle_ship.h
#ifndef BATTLE_SHIP_FUNCTION_H
#define BATTLE_SHIP_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <GL/glut.h>
#include <opencv/cv.h>

#define table 8

//			font.cpp
int Print_Font(const char *format, ...);
void setFontHeight(int Height);
void setCreateFont();
void setFontXY(GLfloat x, GLfloat y);
void setFontFace(const char *FaceName);

//			draw.cpp
void line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat LineWidth = 1);
void Hollow_Square(GLfloat x1, GLfloat y1, GLfloat width, GLfloat height, GLfloat LineWidth = 1);
void Solid_Square(GLfloat x1, GLfloat y1, GLfloat width, GLfloat height);
void checkerboard(GLfloat x, GLfloat y, GLfloat width, GLfloat height, int width_cell, int height_cell, GLfloat LineWidth = 1);
void Counterclockwise_Degree_Rotation(GLfloat x, GLfloat y);

#endif
