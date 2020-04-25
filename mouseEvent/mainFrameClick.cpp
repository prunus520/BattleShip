#include "mainFrameClick.h"

namespace mainFrame{
	void click(int x, int y){
		startTheGame(x, y);
	}
	
	void startTheGame(int x, int y){
		if (mouse.isMouseClickRangeCoordinate(637.6, 807.6, 674, 729)){
			frame = SHIP_POSITION_FRAME;
			releaseImage();
		}
	}
	
	void releaseImage(){
		background.releaseImage();
		title.releaseImage();
	}
}
