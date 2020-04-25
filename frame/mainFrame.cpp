#include "mainFrame.h"

namespace mainFrame{
	void mainFrame(){
		loadBackgroundImage();
		loadTitleImage();
		drawStartFont();
	}
	
	void loadBackgroundImage(){
		if(background.isImageEmpty()){
			background.loadImage();
		}
		background.showImage();
		background.setImageSize(0, 0, windowWidth, windowHeight);
	}
	
	void loadTitleImage(){
		if(title.isImageEmpty()){
			title.loadImage();
		}
		title.showTransparentBackgroundForImage(0, 0, 0, alpha);
		title.setImageSize(centerTitleX(), 20, drawTitleWidth(), drawTitleHight());
		if (alpha < 255)
			alpha++;
	}
	
	GLfloat centerTitleX(){
		return (windowWidth - drawTitleWidth()) / 2;
	}
	
	GLfloat drawTitleWidth(){
		return title.getImageWidth() * 1.5;
	}
	
	GLfloat drawTitleHight(){
		return title.getImageHeight() * 1.5;
	}
	
	void drawStartFont(){
		glDisable(GL_TEXTURE_2D);
		if (glint_START){
			glColor3f(1, 1, 0);
			setFontHeight(55);
			setFontXY(windowWidth / 2 - 80, windowHeight - 190);
			printFont("START");
		}
	}
}
