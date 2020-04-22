#include "mainFrame.h"

void mainFrame(){
	loadBackgroundImage();
	loadTitleImage();
	drawStartFont();
}

void loadBackgroundImage(){
	if(background.isEmpty()){
		background.load();
	}
	background.show();
	background.setSize(0, 0, windowWidth, windowHeight);
}

void loadTitleImage(){
	if(title.isEmpty()){
		title.load();
	}
	title.toTransparent(0, 0, 0, alpha);
	title.setSize(windowWidth / 2 - 360, 20, 508 * 1.5, 105 * 1.5);
	if (alpha < 255)
		alpha++;
	glDisable(GL_TEXTURE_2D);
}

void drawStartFont(){
	if (glint_START){
		glColor3f(1, 1, 0);
		setFontHeight(55);
		setFontXY(windowWidth / 2 - 80, windowHeight - 190);
		Print_Font("START");
	}
}
