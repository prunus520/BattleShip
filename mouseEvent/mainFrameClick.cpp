#include "mainFrameClick.h"

void mainFrameClick(int x, int y){
	startTheGame(x, y);
}

void startTheGame(int x, int y){
	if (x >= 637.6 && x <= 807.6 && y >= 674 && y <= 729){
		frame = SHIP_POSITION_FRAME;
		background.release();
		title.release();
	}
}
