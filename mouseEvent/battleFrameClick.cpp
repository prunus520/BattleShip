#include "battleFrameClick.h"

void battleFrameClick(int state, int x, int y){
	hitPlayerOrComputer(state, x, y);
}

void hitPlayerOrComputer(int state, int x, int y){
	if (state == 1 && mouse.click.x >= 800 && mouse.click.x <= 1340 &&
			mouse.click.y >= 310 && mouse.click.y <= 850 && player_computer_sleep && palyer_down){
		computer.setRow((mouse.click.y - 310) / 67.5);
		computer.setColumn((mouse.click.x - 800) / 67.5);
		player_computer_flag = true;
		palyer_init = true;
	}
}
