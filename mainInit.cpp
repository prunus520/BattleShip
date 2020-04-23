#include "mainInit.h"

Frame frame = MAIN_FRAME;

float windowWidth = 1196 * 1.2, windowHeight = 720 * 1.2;
float scaleX = 1, scaleY = 1;
bool glint_START = true;

Mouse mouse;

Image background("image/background.jpg");
Image title("image/title.png");
Image sea("image/sea.jpg");
Image radarBoard("image/radarBoard.jpg");
Image ship0("image/ship0.png");
Image ship1("image/ship1.png");
Image ship2("image/ship2.png");
Image ship3("image/ship3.png");
Image ship4("image/ship4.png");
Image ship5("image/ship5.png");
Image back("image/back.png");
Image wave("image/wave.jpg");
Image fire("image/fire.png");

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

void glint_START_Timer(int id){
	if (glint_START)
		glint_START = false;
	else
		glint_START = true;

	if (frame == MAIN_FRAME)
		glutTimerFunc(200, glint_START_Timer, id);
}

void transWidthHeight(){
	GLfloat tempf;
	tempf = ship[shipMOVE].getRealWidth();
	ship[shipMOVE].setRealWidth(ship[shipMOVE].getRealHeight());
	ship[shipMOVE].setRealHeight(tempf);
	int tempi;
	tempi = ship[shipMOVE].getLengthWidth();
	ship[shipMOVE].setLengthWidth(ship[shipMOVE].getLengthHeight());
	ship[shipMOVE].setLengthHeight(tempi);
}

bool checkRangeX(int x, int min, int max){
	return x >= min && x <= max;
}

bool checkRangeY(int y, int min, int max){
	return y >= min && y <= max;
}
