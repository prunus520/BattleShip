#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "imageTool.h"

class Image{
	public:
		Image(const char *);
		~Image();
		void loadImage();
		void toRGBImage();
		void releaseImage();
		bool isImageEmpty();
		void showImage();
		void showImage(GLfloat, GLfloat, GLfloat, GLfloat);
		void showPNGImage(uchar = 255, uchar = 255, uchar = 255, uchar = 255);
		void setImageSize(GLfloat, GLfloat, GLfloat, GLfloat);
		void setImageSizeAndColor(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat = 1, GLfloat = 1, GLfloat = 1);
		IplImage *getImage();
		int getImageWidth();
		int getImageHeight();
	private:
		IplImage *image = nullptr;
		const char *title;
};

#endif
