#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H

#include "../mainInit.h"

namespace battleFrame{
	void display();
	
	void loadSeaImage();
	
	void drawCheckerBoard();
	void drawPlayerCheckerBoard();
	void drawComputerCheckerBoard();
	void printCheckerBoardMark(GLfloat, GLfloat, GLfloat, GLfloat);
	void printCheckerBoardAlphabet(GLfloat, GLfloat);
	void printCheckerBoardNumber(GLfloat, GLfloat);
	
	void loadPlayerShipsGroupImage();
	void initializeCoordinate();
	
	void loadHitImage();
	void loadFireImage();
	void loadWaveImage();
	void showHitImage();
	
	void judgeGame();
	void judgePlayerOrComputer();
	void player_computer_sleep_Timer(int);
	void player_computer_flag_Timer(int);
	void printWinOrLoseFont();
}

#endif
