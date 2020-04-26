#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H

#include "../mainInit.h"

namespace battleFrame{
	void display();
	
	void loadSeaImage();
	
	void drawCheckerBoard();
	void drawPlayerCheckerBoard();
	void drawComputerCheckerBoard();
	void drawCheckerBoardMark(GLfloat, GLfloat, GLfloat, GLfloat);
	void drawCheckerBoardAlphabet(GLfloat, GLfloat);
	void drawCheckerBoardNumber(GLfloat, GLfloat);
	
	void loadPlayerShipsGroupImage();
	void initializeCoordinate();
	
	void loadHitImage();
	void loadFireImage();
	void loadWaveImage();
	void showHitAndnHitImage();
	void showHitImage(int, int, int, int);
	void shownHitImage(int, int, int, int);
	
	void judgeGame();
	void judgePlayerOrComputerRound();
	void player_computer_sleep_Timer(int);
	void isComputerTimer(int);
	void drawWinOrLoseFont();
}

#endif
