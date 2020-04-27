#include "battleFrameClick.h"

namespace battleFrameClick{
	void battleFrameClick(int state, int x, int y){
		hitComputerShip(state, x, y);
		if (computer.isLose() || player.isLose()){
			replayTheGame();
		}
	}
	
	void hitComputerShip(int state, int x, int y){
		if (state == 1 && mouse.isMouseClickRangeCoordinate(800, 1340, 310, 850) && isPalyerMouseClickedUp){
			computer.setRow((y - 310) / 67.5);
			computer.setColumn((x - 800) / 67.5);
			if(computer.hitSuccess()){
				isComputer = true;
			}
		}
	}
	
	void replayTheGame(){
		if (mouse.isMouseClickRangeCoordinate(575, 777, 105, 146)){
			frame = MAIN_FRAME;
			releaseImage();
		}
	}
	
	void releaseImage(){
		sea.releaseImage();
		for (int i = 5; i != -1; --i){
			ship[i].releaseImage();
		}
		fire.releaseImage();
		wave.releaseImage();
	}
}
