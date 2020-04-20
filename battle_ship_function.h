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

#define ESC 27

//			gult secial key
#define F1 GLUT_KEY_F1
#define F2 GLUT_KEY_F2
#define F3 GLUT_KEY_F3
#define F4 GLUT_KEY_F4
#define F5 GLUT_KEY_F5
#define F6 GLUT_KEY_F6
#define F7 GLUT_KEY_F7
#define F8 GLUT_KEY_F8
#define F9 GLUT_KEY_F9
#define F10 GLUT_KEY_F10
#define F11 GLUT_KEY_F11
#define F12 GLUT_KEY_F12
#define LEFT GLUT_KEY_LEFT
#define UP GLUT_KEY_UP
#define RIGHT GLUT_KEY_RIGHT
#define DOWN GLUT_KEY_DOWN
#define PGUP GLUT_KEY_PAGE_UP
#define PGDN GLUT_KEY_PAGE_DOWN
#define HOME GLUT_KEY_HOME
#define END GLUT_KEY_END
#define INSERT GLUT_KEY_INSERT

//			battle_ship_color
#define battle_ship_alarm_red glColor3f(0.4372, 0.0313, 0.0941)
#define battle_ship_alarm_green glColor3f(0.0941, 0.4372, 0.0313)
#define battle_ship_green glColor3f(0.0941, 0.5372, 0.0313)
#define battle_ship_blue glColor3f(0, 0, 1)

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
