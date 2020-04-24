#include "mainFrameClick.h"

void mainFrameClick(int x, int y){
	startTheGame(x, y);
}

void startTheGame(int x, int y){
	if (checkRangeX(x, 637.6, 807.6) && checkRangeY(y, 674, 729)){
		frame = SHIP_POSITION_FRAME;
		releaseMainImage();
	}
}

void releaseMainImage(){
	background.releaseImage();
	title.releaseImage();
}
