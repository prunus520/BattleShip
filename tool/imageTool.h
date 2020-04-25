#ifndef IMAGETOOL_H
#define IMAGETOOL_H

#include <windows.h>
#include <GL/glut.h>
#include <opencv/cv.h>

void showImage(IplImage*);
void toTransparentImage(IplImage*, uchar = 255, uchar = 255, uchar = 255, uchar = 255);
void setImageSize(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat = 1, GLfloat = 1, GLfloat = 1);

#endif
