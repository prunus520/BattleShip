#include "shipPositionFrame.h"

namespace shipPositionFrame{
	void display(){
		randomComputerShips();
		loadImage();
		drawCheckerBoard();
	}
	
	bool isRandomShip = false;
	void randomComputerShips(){
		if (!isRandomShip){
			computer.randomShips();
			isRandomShip = true;
		}
	}
	
	void loadImage(){
		loadRadarBoardImage();
		loadBackImage();
		loadShipsGroupImage();
	}
	
	void loadRadarBoardImage(){
		if (radarBoard.isImageEmpty()){
			radarBoard.loadImage();
		}
		radarBoard.showImage(0, 0, windowWidth, windowHeight);
	}
	
	void loadBackImage(){
		if (back.isImageEmpty()){
			back.loadImage();
		}
		back.showPNGImage();
		back.setImageSize(0, 0, 100, 100);
	}
	
	void loadShipsGroupImage(){
		setShipsData();
		loadShipsImage();
	}
	
	void setShipsData(){
		if (ship[0].isImageEmpty()){
			int position[6][2] = {{1108, 186}, {1161, 186}, {1228, 186}, {1100, 280}, {1202, 280}, {1010, 170}};
			float size[6][2] = {{16, 67.2}, {24, 65.6}, {16, 67.2}, {65, 212.5}, {50, 212.5}, {54, 336}};
			int length[6][2] = {{1, 1}, {1, 1}, {1, 1}, {1, 3}, {1, 3}, {1, 5}};
			for (int i = 5; i != -1; --i){
				ship[i].loadImage();
				ship[i].setShipPosition(position[i][0], position[i][1]);
				ship[i].setShipSize(size[i][0], size[i][1]);
				ship[i].setShipLength(length[i][0], length[i][1]);
			}
		}
	}
	
	void loadShipsImage(){
		for (int i = 5; i != -1; --i){
			ship[i].showPNGImage();
			loadShipShadowImage(i);
			loadGreenShipImage(i);
			initializeCoordinate();
		}
	}
	
	void loadShipShadowImage(int i){
		ship[i].setImageSizeAndColor(ship[i].getShipPositionX(), ship[i].getShipPositionY(), ship[i].getShipSizeWidth(), ship[i].getShipSizeHeight(), 0, 0, 0);
	}
	
	void loadGreenShipImage(int i){
		if (ship[i].getShipRotation()){
			ship[i].rotateShipImage();
		}
		ship[i].setImageSizeAndColor(ship[i].getShipCoordinateX(), ship[i].getShipCoordinateY(), ship[i].getShipSizeWidth(), ship[i].getShipSizeHeight(), 0, 1, 0);
	}
	
	void initializeCoordinate(){
		glLoadIdentity();
		gluOrtho2D(0, windowWidth, windowHeight, 0);
	}
	
	void drawCheckerBoard(){
		useGreenPaint();
		checkerboard(123, 167, 578, 578, table, table, 2);
	}
	
	void useGreenPaint(){
		glDisable(GL_TEXTURE_2D);
		glColor3f(0.0941, 0.5372, 0.0313);
	}
}
