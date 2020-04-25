#include "image.h"

Image::Image(const char *imagePath){
	title = imagePath;
}

Image::~Image(){
	releaseImage();
}

void Image::loadImage(){
	image = cvLoadImage(title);
	toRGBImage();
}

void Image::toRGBImage(){
	cvCvtColor(image, image, CV_BGR2RGB);
}

void Image::releaseImage(){
	cvReleaseImage(&image);
}

bool Image::isImageEmpty(){
	return image == nullptr;
}

void Image::showImage(){
	::showImage(image);
}

void Image::showImage(GLfloat x, GLfloat y, GLfloat width, GLfloat height){
	::showImage(image);
	::setImageSize(x, y, width, height);
}

void Image::showPNGImage(uchar red, uchar green, uchar blue, uchar alpha){
	toTransparentImage(image, red, green, blue, alpha);
}

void Image::setImageSize(GLfloat x, GLfloat y, GLfloat width, GLfloat height){
	::setImageSize(x, y, width, height);
}

void Image::setImageSizeAndColor(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat red, GLfloat green, GLfloat blue){
	::setImageSize(x, y, width, height, red, green, blue);
}

IplImage *Image::getImage(){
	return image;
}

int Image::getImageWidth(){
	return image->width;
}

int Image::getImageHeight(){
	return image->height;
}
