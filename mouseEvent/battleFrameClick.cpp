#include "battleFrameClick.h"

void battleFrameClick(int state, int x, int y){
	hitPlayerOrComputer(state, x, y);
}

void hitPlayerOrComputer(int state, int x, int y){
	if (state == 1 && mouse.getClickX() >= 800 && mouse.getClickX() <= 1340 &&
			mouse.getClickY() >= 310 && mouse.getClickY() <= 850 && player_computer_sleep && palyer_down){
		computer.setRow((mouse.getClickY() - 310) / 67.5);
		computer.setColumn((mouse.getClickX() - 800) / 67.5);
		player_computer_flag = true;
		palyer_init = true;
	}
}
