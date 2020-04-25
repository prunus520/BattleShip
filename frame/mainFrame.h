#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "../mainInit.h"

namespace mainFrame{
	void display();
	
	void loadImage();
	void loadBackgroundImage();
	extern uchar alpha;
	void loadTitleImage();
	void floatImage();
	
	GLfloat centerTitleX();
	GLfloat imageTitleWidth();
	GLfloat imageTitleHight();
	
	void drawFont();
	extern bool isTimer;
	void setTimer();
	extern bool isFlicker;
	void flickerFontTimer(int);
	void drawFlickeringStartFont();
}

#endif
