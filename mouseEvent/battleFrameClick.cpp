#include "battleFrameClick.h"

void battleFrameClick(int state, int x, int y){
	hitPlayerOrComputer(state, x, y);
}

void hitPlayerOrComputer(int state, int x, int y){
	if (state == 1 && button_mouseX >= 800 && button_mouseX <= 1340 &&
			button_mouseY >= 310 && button_mouseY <= 850 && player_computer_sleep && palyer_down){
		computer.setRow((button_mouseY - 310) / 67.5);
		computer.setColumn((button_mouseX - 800) / 67.5);
		player_computer_flag = true;
		palyer_init = true;
	}
}
