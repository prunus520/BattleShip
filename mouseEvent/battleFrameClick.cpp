#include "battleFrameClick.h"

namespace battleFrameClick{
	void battleFrameClick(int state, int x, int y){
		hitPlayerOrComputer(state, x, y);
	}
	
	void hitPlayerOrComputer(int state, int x, int y){
		if (state == 1 && x >= 800 && x <= 1340 &&
				y >= 310 && y <= 850 && player_computer_sleep && palyer_down){
			computer.setRow((y - 310) / 67.5);
			computer.setColumn((x - 800) / 67.5);
			player_computer_flag = true;
			palyer_init = true;
		}
	}
}
