#include "battleFrameClick.h"

void battleFrameClick(int state, int x, int y){
	hitPlayerOrComputer(state, x, y);
}

void hitPlayerOrComputer(int state, int x, int y){
	if (state == 1 && mouseClickX >= 800 && mouseClickX <= 1340 &&
			mouseClickY >= 310 && mouseClickY <= 850 && player_computer_sleep && palyer_down){
		computer.setRow((mouseClickY - 310) / 67.5);
		computer.setColumn((mouseClickX - 800) / 67.5);
		player_computer_flag = true;
		palyer_init = true;
	}
}
