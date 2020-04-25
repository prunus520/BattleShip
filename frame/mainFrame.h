#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "../mainInit.h"

namespace mainFrame{
	extern uchar alpha;
	extern bool isTimer;
	extern bool isFlicker;
	
	void display();
	
	void loadImage();
	void loadBackgroundImage();
	void loadTitleImage();
	
	GLfloat centerTitleX();
	GLfloat drawTitleWidth();
	GLfloat drawTitleHight();
	
	void printFont();
	void setTimer();
	void flickerFontTimer(int);
	void printFlickeringStartFont();
}

#endif
