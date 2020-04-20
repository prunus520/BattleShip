#ifndef IMAGETOOL_H
#define IMAGETOOL_H

#include <windows.h>
#include <GL/glut.h>
#include <opencv/cv.h>

void showImage(IplImage *img);
void toTransparentImage(IplImage *img, uchar red = 255, uchar green = 255, uchar blue = 255, uchar alpha = 255);
void setImageSize(GLfloat x1, GLfloat y1, GLfloat width, GLfloat height, GLfloat red = 1, GLfloat green = 1, GLfloat blue = 1);

#endif
