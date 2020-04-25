#include "shipPositionFrame.h"

namespace shipPositionFrame{
	void shipPositionFrame(){
		randomComputerShips();
		loadRadarBoardImage();
		loadBackImage();
		loadShipGroupImage();
		drawCheckerBoard();
	}
	
	void randomComputerShips(){
		static bool isRandomShip = false;
		if(!isRandomShip){
			srand(time(NULL));
			computer.randomShips();
			isRandomShip = true;
		}
	}
	
	void loadRadarBoardImage(){
		if(radarBoard.isImageEmpty()){
			radarBoard.loadImage();
		}
		radarBoard.showImage();
		radarBoard.setImageSize(0, 0, windowWidth, windowHeight);
	}
	
	void loadBackImage(){
		if(back.isImageEmpty()){
			back.loadImage();
		}
		back.showTransparentBackgroundForImage();
		back.setImageSize(0, 0, 100, 100);
	}
	
	void loadShipGroupImage(){
		useGreenPaint();
		if(ship[0].isImageEmpty()){
			int position[6][2] = {{1108, 186}, {1161, 186}, {1228, 186}, {1100, 280}, {1202, 280}, {1010, 170}};
			float size[6][2] = {{16, 67.2}, {24, 65.6}, {16, 67.2}, {65, 212.5}, {50, 212.5}, {54, 336}};
			int length[6][2] = {{1, 1}, {1, 1}, {1, 1}, {1, 3}, {1, 3}, {1, 5}};
			for(int i = 5; i != -1; --i){
				ship[i].loadImage();
				ship[i].setShipPosition(position[i][0], position[i][1]);
				ship[i].setShipSize(size[i][0], size[i][1]);
				ship[i].setShipLength(length[i][0], length[i][1]);
			}
		}
		for (int i = 5; i != -1; --i){
			ship[i].showTransparentBackgroundForImage();
			ship[i].setImageSizeAndColor(ship[i].getShipPositionX(), ship[i].getShipPositionY(), ship[i].getShipSizeWidth(), ship[i].getShipSizeHeight(), 0, 0, 0);
			if (ship[i].getShipRotation())
				Counterclockwise_Degree_Rotation(ship[i].getNewShipPositionX(), ship[i].getNewShipPositionY());
	
			ship[i].setImageSizeAndColor(ship[i].getNewShipPositionX(), ship[i].getNewShipPositionY(), ship[i].getShipSizeWidth(), ship[i].getShipSizeHeight(), 0, 1, 0);
			glLoadIdentity();
			gluOrtho2D(0, windowWidth, windowHeight, 0);
		}
	}
	
	void useGreenPaint(){
		glDisable(GL_TEXTURE_2D);
		glColor3f(0.0941, 0.5372, 0.0313);
	}
	
	void drawCheckerBoard(){
		useGreenPaint();
		checkerboard(123, 167, 578, 578, table, table, 2);
	}
}
