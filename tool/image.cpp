#include "image.h"

Image::Image(const char *imagePath){
	title = imagePath;
}

Image::~Image(){
	release();
}

void Image::load(){
	image = cvLoadImage(title);
	toRGB();
}

void Image::release(){
	cvReleaseImage(&image);
}

bool Image::isEmpty(){
	return image == nullptr;
}

void Image::toRGB(){
	cvCvtColor(image, image, CV_BGR2RGB);
}

IplImage *Image::getImage(){
	return image;
}

void Image::show(bool isTransparentBackground){
	if(isTransparentBackground){
		toTransparentImage(image);
	}else{
		showImage(image);
	}
}

void Image::toTransparent(uchar red, uchar green, uchar blue, uchar alpha){
	toTransparentImage(image, red, green, blue, alpha);
}

void Image::setSize(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat red, GLfloat green, GLfloat blue){
	setImageSize(x, y, width, height, red, green, blue);
}

int Image::getWidth(){
	return image->width;
}

int Image::getHeight(){
	return image->height;
}
