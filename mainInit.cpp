#include "mainInit.h"

Frame frame = MAIN_FRAME;

float windowWidth = 1196 * 1.2, windowHeight = 720 * 1.2;
float scaleX = 1, scaleY = 1;

Mouse mouse;

Image background("image/background.jpg");
Image title("image/title.png");
Image sea("image/sea.jpg");
Image radarBoard("image/radarBoard.jpg");
ShipImage ship[6] = {"image/ship0.png", "image/ship1.png",
									"image/ship2.png", "image/ship3.png",
									"image/ship4.png", "image/ship5.png"};
Image back("image/back.png");
Image wave("image/wave.jpg");
Image fire("image/fire.png");

int shipMOVE = -1;
bool player_computer_flag = true;
bool player_computer_sleep = false;
bool palyer_init = false;
bool palyer_down = true;

Battleship computer, player;

void player_computer_sleep_Timer(int id){
	if (player_computer_sleep)
		player_computer_sleep = false;
	else
		player_computer_sleep = true;
}

void player_computer_flag_Timer(int id){
	if (player_computer_flag){
		player_computer_flag = false;
		do{
			player.setRow(rand() % 8);
			player.setColumn(rand() % 8);
		} while (player.getBoardCell() != -1);
	}
	else if (player_computer_sleep == false)
		player_computer_flag = true;
}

bool checkRangeX(int x, int min, int max){
	return x >= min && x <= max;
}

bool checkRangeY(int y, int min, int max){
	return y >= min && y <= max;
}
