#include "image.h"

Image::Image(const char *imagePath){
	image = cvLoadImage(imagePath);
	cvCvtColor(image, image, CV_BGR2RGB);
}

Image::~Image(){
	cvReleaseImage(&image);
}

void Image::toBGR(){
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

