#include "battleFrameClick.h"

namespace battleFrameClick{
	void battleFrameClick(int state, int x, int y){
		hitComputerShip(state, x, y);
	}
	
	void hitComputerShip(int state, int x, int y){
		if (state == 1 && mouse.isMouseClickRangeCoordinate(800, 1340, 310, 850) && player_computer_sleep && isPalyerMouseClickedUp){
			computer.setRow((y - 310) / 67.5);
			computer.setColumn((x - 800) / 67.5);
			player_computer_flag = true;
			palyer_init = true;
		}
	}
}
