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
		void load();
		void toBGR();
		IplImage *getImage();
		void show();
		void toTransparent(uchar = 255, uchar = 255, uchar = 255, uchar = 255);
	private:
		IplImage *image = nullptr;
		const char *title;
};

#endif
