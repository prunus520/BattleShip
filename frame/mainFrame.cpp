#include "mainFrame.h"

namespace mainFrame{
	void display(){
		loadImage();
		drawFont();
	}
	
	void loadImage(){
		loadBackgroundImage();
		loadTitleImage();
	}
	
	void loadBackgroundImage(){
		if(background.isImageEmpty()){
			background.loadImage();
		}
		background.showImage(0, 0, windowWidth, windowHeight);
	}
	
	uchar alpha;
	void loadTitleImage(){
		if(title.isImageEmpty()){
			title.loadImage();
			alpha = 0;
		}
		floatImage();
	}
	
	void floatImage(){
		title.showPNGImage(0, 0, 0, alpha);
		title.setImageSize(centerTitleX(), 20, imageTitleWidth(), imageTitleHight());
		if (alpha < 255){
			++alpha;
		}
	}
	
	GLfloat centerTitleX(){
		return (windowWidth - imageTitleWidth()) / 2;
	}
	
	GLfloat imageTitleWidth(){
		return title.getImageWidth() * 1.5;
	}
	
	GLfloat imageTitleHight(){
		return title.getImageHeight() * 1.5;
	}
	
	void drawFont(){
		setTimer();
		drawFlickeringStartFont();
	}
	
	bool isTimer = false;
	void setTimer(){
		if(!isTimer){
			glutTimerFunc(200, flickerFontTimer, 1);
			isTimer = true;
		}
	}
	
	bool isFlicker = true;
	void flickerFontTimer(int id){
		isFlicker = !isFlicker;
		glutTimerFunc(200, flickerFontTimer, id);
	}
	
	void drawFlickeringStartFont(){
		if (isFlicker){
			glDisable(GL_TEXTURE_2D);
			glColor3f(1, 1, 0);
			setFontHeight(55);
			setFontXY(windowWidth / 2 - 80, windowHeight - 190);
			::printFont("START");
		}
	}
}
