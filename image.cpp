#include "image.h"

Image::Image(const char *imagePath){
	title = imagePath;
}

Image::~Image(){
	cvReleaseImage(&image);
}

void Image::load(){
	image = cvLoadImage(title);
	cvCvtColor(image, image, CV_BGR2RGB);
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

