#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "imageTool.h"

class Image{
	public:
		Image(const char*);
		~Image();
		IplImage *getImage();
		void load();
		void release();
		bool isEmpty();
		void show();
		void toTransparent(uchar = 255, uchar = 255, uchar = 255, uchar = 255);
		void setSize(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat = 1, GLfloat = 1, GLfloat = 1);
	private:
		IplImage *image = nullptr;
		const char *title;
		void toRGB();
};

#endif
