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
		drawCheckerBoardMark(85, 314, 140, 247);
		checkerboard(140, 310, 540, 540, table, table, 5);
	}
	
	void drawComputerCheckerBoard(){
		drawCheckerBoardMark(745, 314, 800, 247);
		checkerboard(800, 310, 540, 540, table, table, 5);
	}
	
	void drawCheckerBoardMark(GLfloat alphabetX, GLfloat alphabetY, GLfloat numberX, GLfloat numberY){
		glColor3f(0, 0, 1);
		setFontHeight(67);
		drawCheckerBoardAlphabet(alphabetX, alphabetY);
		drawCheckerBoardNumber(numberX, numberY);
	}
	
	void drawCheckerBoardAlphabet(GLfloat x, GLfloat y){
		setFontXY(x, y);
		for (int i = 65; i != 65 + table; ++i){
			printFont("%c\n", i);
		}
	}
	
	void drawCheckerBoardNumber(GLfloat x, GLfloat y){
		setFontXY(x, y);
		for (int i = 1; i != 1 + table; ++i){
			printFont("% d ", i);
		}
	}
	
	void loadPlayerShipsGroupImage(){
		for (int i = 5; i != -1; --i){
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
		showHitAndnHitImage();
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
	
	void showHitAndnHitImage(){
		showHitImage(140, 310, 800, 310);
		shownHitImage(140, 310, 800, 310);
		
	}
	
	void showHitImage(int playerX, int playerY, int computerX, int computerY){
		for (int row = 0; row != 8; ++row){
			for (int column = 0; column != 8; ++column){
				if (player.getBoardCell(row, column) == isHit){
					fire.showPNGImage();
					setImageSize(playerX + 1.5 + column * 67.5, playerY + 1.5 + row * 67.5, 64.5, 64.5);
				}
				if (computer.getBoardCell(row, column) == isHit){
					fire.showPNGImage();
					setImageSize(computerX + 1.5 + column * 67.5, computerY + 1.5 + row * 67.5, 64.5, 64.5);
				}
			}
		}
	}
	
	void shownHitImage(int playerX, int playerY, int computerX, int computerY){
		for (int row = 0; row != 8; ++row){
			for (int column = 0; column != 8; ++column){
				if (player.getBoardCell(row, column) == isnHit){
					wave.showImage();
					setImageSize(playerX + 1.5 + column * 67.5, playerY + 1.5 + row * 67.5, 64.5, 64.5);
				}
				if (computer.getBoardCell(row, column) == isnHit){
					wave.showImage();
					setImageSize(computerX + 1.5 + column * 67.5, computerY + 1.5 + row * 67.5, 64.5, 64.5);
				}
			}
		}
	}
	
	void judgeGame(){
		judgePlayerOrComputerRound();
		drawWinOrLoseFont();
	}
	
	bool isInitGame = false;
	void judgePlayerOrComputerRound(){
		if (isComputer && isPalyerMouseClickedUp){
			glutTimerFunc(500, isComputerTimer, 3);
			isPalyerMouseClickedUp = false;
		}
		else if (!isComputer){
			isPalyerMouseClickedUp = true;
			isInitGame = true;
		}
		if (isInitGame && !isPalyerMouseClickedUp){
			drawHitShipFont();
		}
	}
	
	void isComputerTimer(int id){
		if (isComputer){
			player.randomHit();
		}
		isComputer = !isComputer;
	}
	
	void drawHitShipFont(){
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glColor3f(0, 0, 0);
		setFontHeight(65);
		setFontXY(270, 100);
		switch (computer.hitShips()){
			case 0:
				break;
			case 1:
				printFont("You hit a ship with the shot ( %d , %d )", computer.getRow() + 1, computer.getColumn() + 1);
				break;
			case 2:
				printFont("Hit a ship with the shot ( %d , %d )", computer.getRow() + 1, computer.getColumn() + 1);
				break;
			case 3:
				setFontXY(600, 100);
				printFont("Oops !");
				break;
			case 4:
				setFontXY(350, 100);
				printFont("Where did you shoot ? Noob !");
				break;
		}
	}
	
	void drawWinOrLoseFont(){
		if (computer.isLose() || player.isLose()){
			glColor3f(0, 0, 0);
			setFontHeight(55);
			
			if (computer.isLose()){
				setFontXY(577, 100);
				printFont("You win.");
			}
			else if (player.isLose()){
				setFontXY(566, 100);
				printFont("You lose.");
			}
			isPalyerMouseClickedUp = false;
		}
	}
}
