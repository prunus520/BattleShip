#ifndef IMAGE_H
#define IMAGE_H

#include <GL/glut.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "imageTool.h"

class Image{
	public:
		Image(const char*);
		~Image();
		void toBGR();
		IplImage *getImage();
		void show();
		void toTransparent(uchar = 255, uchar = 255, uchar = 255, uchar = 255);
	private:
		IplImage *image;
};

#endif
