#include "mainInit.h"

Frame frame = MAIN_FRAME;

float windowWidth = 1196 * 1.2, windowHeight = 720 * 1.2;
float sizeMagn = 1;
bool glint_START = true;
int mouseX, mouseY;
int button_mouseX, button_mouseY;
int move_mouseX, move_mouseY;
int pointX = windowWidth, pointY = 0;

Image background("img//background.jpg");
Image title("img//title.png");
Image sea("img//sea.jpg");
Image radarBoard("img//radarBoard.jpg");
Image ship0("img//ship0.png");
Image ship1("img//ship1.png");
Image ship2("img//ship2.png");
Image ship3("img//ship3.png");
Image ship4("img//ship4.png");
Image ship5("img//ship5.png");
Image back("img//back.png");
Image wave("img//wave.jpg");
Image fire("img//fire.png");

int mouse_down;
int shipMOVE = -1;
bool player_computer_flag = true;
bool player_computer_sleep = false;
bool palyer_init = false;
bool palyer_down = true;
uchar alpha = 0;

Battleship computer, player;
Ship ship[6];

void shipXY(GLfloat x, GLfloat y, GLfloat width, GLfloat height){
	ship[shipMOVE].setNewCoordinate(x + ship[shipMOVE].getHeadColumn() * width / 8 + (ship[shipMOVE].getLengthWidth() * width / 8 - ship[shipMOVE].getRealWidth()) / 2,
																	y + ship[shipMOVE].getHeadRow() * height / 8 + (ship[shipMOVE].getLengthHeight() * height / 8 - ship[shipMOVE].getRealHeight()) / 2);
}

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
