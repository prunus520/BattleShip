#include "battleFrame.h"

void battleFrame(){
	loadSeaImage();
	drawPlayerCheckerBoard();
	drawComputerCheckerBoard();
	loadPlayerShipGroupImage();
	judgePlayerOrComputer();
	judgeToHit();
	Sleep(100);
	drawWinOrLoseFont();
}

void loadSeaImage(){
	if(sea.isEmpty()){
		sea.load();
	}
	sea.show();
	sea.setSize(0, 0, windowWidth, windowHeight);
}

void drawPlayerCheckerBoard(){
	glColor3f(0, 0, 1);
	setFontHeight(67);
	
	setFontXY(85, 314);
	for (int i = 65; i < 65 + table; i++)
		printFont("%c\n", i);
	setFontXY(140, 247);
	for (int i = 1; i < 1 + table; i++)
		printFont("% d ", i);
	checkerboard(140, 310, 540, 540, table, table, 5);
}

void drawComputerCheckerBoard(){
	glColor3f(0, 0, 1);
	setFontHeight(67);
	
	setFontXY(745, 314);
	for (int i = 65; i < 65 + table; i++)
		printFont("%c\n", i);
	setFontXY(800, 247);
	for (int i = 1; i < 1 + table; i++)
		printFont("% d ", i);
	checkerboard(800, 310, 540, 540, table, table, 5);
}

void loadPlayerShipGroupImage(){
	for (int i = 5; i >= 0; i--){
		shipMOVE = i;
		shipXY(140, 310, 540, 540);
		toTransparentImage(ship[i].getImage());
		if (ship[shipMOVE].getRealWidth() > ship[shipMOVE].getRealHeight() || ship[i].getRotation())
			Counterclockwise_Degree_Rotation(ship[i].getNewX(), ship[i].getNewY());
		setImageSize(ship[i].getNewX(), ship[i].getNewY(), ship[i].getWidth(), ship[i].getHeight(), 1, 1, 1);
		glLoadIdentity();
		gluOrtho2D(0, windowWidth, windowHeight, 0);
	}
}

void judgePlayerOrComputer(){
	if (player_computer_flag && player_computer_sleep == false)
		glutTimerFunc(1, player_computer_sleep_Timer, 2);

	if (player_computer_flag && player_computer_sleep && palyer_down && palyer_init){
		computer.checkShots();
		glutTimerFunc(500, player_computer_flag_Timer, 3);
		palyer_down = false;
		palyer_init = false;
	}
	else if (player_computer_flag == false && player_computer_sleep){
		player.checkShots();
		palyer_down = true;
		palyer_init = true;
	}
}

void judgeToHit(){
	if(fire.isEmpty()){
		fire.load();
	}
	if(wave.isEmpty()){
		wave.load();
	}
	player.showBoard(140, 310, fire.getImage(), wave.getImage());
	computer.showBoard(800, 310, fire.getImage(), wave.getImage());
}

void drawWinOrLoseFont(){
	glColor3f(0, 0, 0);
	setFontHeight(55);
	setFontXY(windowWidth / 2 - 260, windowHeight / 2);

	if (computer.getHitCell(0) == 14 || computer.getHitCell(1) == 40 || player.getHitCell(0) == 14 || player.getHitCell(1) == 40){
		if (computer.getHitCell(0) == 14)
			printFont("You win the game");
		else if (computer.getHitCell(1) == 40)
			printFont("You are garbage");
		if (player.getHitCell(0) == 14)
			printFont("You lose the game");
		else if (player.getHitCell(1) == 40)
			printFont("You are garbage");
		palyer_down = false;
	}
}
