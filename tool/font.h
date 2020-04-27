#ifndef FONT_H
#define FONT_H

#include <cstdio>
#include <windows.h>
#include "../library/include/GL/glut.h"

int printFont(const char *, ...);
void setFontHeight(int);
void setCreateFont();
void setFontXY(GLfloat, GLfloat);
void setFontFace(const char *);

#endif
