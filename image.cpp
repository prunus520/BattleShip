#include "image.h"

Image::Image(const char *imagePath){
	title = imagePath;
	image = cvLoadImage(title);
	toRGB();
}

Image::~Image(){
	cvReleaseImage(&image);
}

void Image::toRGB(){
	cvCvtColor(image, image, CV_BGR2RGB);
}

IplImage *Image::getImage(){
	return image;
}

void Image::show(){
	showImage(image);
}

void Image::toTransparent(uchar red, uchar green, uchar blue, uchar alpha){
	toTransparentImage(image, red, green, blue, alpha);
}

void Image::setSize(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat red, GLfloat green, GLfloat blue){
	setImageSize(x, y, width, height, red, green, blue);
}
