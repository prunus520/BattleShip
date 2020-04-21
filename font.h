#ifndef FONT_H
#define FONT_H

#include <stdio.h>
#include <windows.h>
#include <GL/glut.h>

int Print_Font(const char *format, ...);
void setFontHeight(int Height);
void setCreateFont();
void setFontXY(GLfloat x, GLfloat y);
void setFontFace(const char *FaceName);

#endif
