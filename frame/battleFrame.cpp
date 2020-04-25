#include "battleFrame.h"

namespace battleFrame{
	void display(){
		loadSeaImage();
		drawCheckerBoard();
		loadPlayerShipsGroupImage();
		loadHitImage();
		judgeGame();
	}
	
	void loadSeaImage(){
		if(sea.isImageEmpty()){
			sea.loadImage();
		}
		sea.showImage();
		sea.setImageSize(0, 0, windowWidth, windowHeight);
	}
	
	void drawCheckerBoard(){
		drawPlayerCheckerBoard();
		drawComputerCheckerBoard();
	}
	
	void drawPlayerCheckerBoard(){
		printCheckerBoardMark(85, 314, 140, 247);
		checkerboard(140, 310, 540, 540, table, table, 5);
	}
	
	void drawComputerCheckerBoard(){
		printCheckerBoardMark(745, 314, 800, 247);
		checkerboard(800, 310, 540, 540, table, table, 5);
	}
	
	void printCheckerBoardMark(GLfloat alphabetX, GLfloat alphabetY, GLfloat numberX, GLfloat numberY){
		glColor3f(0, 0, 1);
		setFontHeight(67);
		printCheckerBoardAlphabet(alphabetX, alphabetY);
		printCheckerBoardNumber(numberX, numberY);
	}
	
	void printCheckerBoardAlphabet(GLfloat x, GLfloat y){
		setFontXY(x, y);
		for (int i = 65; i < 65 + table; i++)
			printFont("%c\n", i);
	}
	
	void printCheckerBoardNumber(GLfloat x, GLfloat y){
		setFontXY(x, y);
		for (int i = 1; i < 1 + table; i++)
			printFont("% d ", i);
	}
	
	void loadPlayerShipsGroupImage(){
		for (int i = 5; i >= 0; i--){
			ship[i].placeShipInCell(140, 310, 540, 540);
			ship[i].showPNGImage();
			if (ship[i].getShipRotation()){
				ship[i].rotateShipImage();
			}
			ship[i].loadShipCoordinate();
			initializeCoordinate();
		}
	}
	
	void initializeCoordinate(){
		glLoadIdentity();
		gluOrtho2D(0, windowWidth, windowHeight, 0);
	}

	void loadHitImage(){
		loadFireImage();
		loadWaveImage();
		showHitImage();
	}
	
	void loadFireImage(){
		if(fire.isImageEmpty()){
			fire.loadImage();
		}
	}
	
	void loadWaveImage(){
		if(wave.isImageEmpty()){
			wave.loadImage();
		}
	}
	
	void showHitImage(){
		player.showHitImage(140, 310, fire.getImage(), wave.getImage());
		computer.showHitImage(800, 310, fire.getImage(), wave.getImage());
	}
	
	void judgeGame(){
		judgePlayerOrComputer();
		Sleep(100);
		printWinOrLoseFont();
	}
	
	void judgePlayerOrComputer(){
		if (player_computer_flag && player_computer_sleep == false){
			glutTimerFunc(1, player_computer_sleep_Timer, 2);
		}
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
	
	void player_computer_sleep_Timer(int id){
		player_computer_sleep = !player_computer_sleep;
	}
	
	void player_computer_flag_Timer(int id){
		player_computer_flag = !player_computer_flag;
		if (player_computer_flag){
			do{
				player.setRow(rand() % 8);
				player.setColumn(rand() % 8);
			} while (player.getBoardCell() != -1);
		}
	}
	
	void printWinOrLoseFont(){
		if (computer.getHitShipCell() == 14 || computer.getHitCell() == 40 || player.getHitShipCell() == 14 || player.getHitCell() == 40){
			glColor3f(0, 0, 0);
			setFontHeight(55);
			setFontXY(windowWidth / 2 - 260, windowHeight / 2);
			
			if (computer.getHitShipCell() == 14){
				printFont("You win.");
			}
			else if (player.getHitShipCell() == 14){
				printFont("You lose.");
			}
			else if (computer.getHitCell() == 40 || player.getHitCell() == 40){
				printFont("You are garbage.");
			}
			palyer_down = false;
		}
	}
}
