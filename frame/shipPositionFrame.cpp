#include "shipPositionFrame.h"

void shipPositionFrame(){
	loadRadarBoardImage();
	loadBackImage();
	useGreenPaint();
	drawCheckerBoard();
	loadShipGroupImage();
	moveShipByMouse();
	drawTestTable();
}

void loadRadarBoardImage(){
	if(radarBoard.isEmpty()){
		radarBoard.load();
	}
	radarBoard.show();
	radarBoard.setSize(0, 0, windowWidth, windowHeight);
}

void loadBackImage(){
	if(back.isEmpty()){
		back.load();
	}
	back.toTransparent();
	back.setSize(0, 0, 100, 100);
	glDisable(GL_TEXTURE_2D);
}

void useGreenPaint(){
	glColor3f(0.0941, 0.5372, 0.0313);
}

void drawCheckerBoard(){
	checkerboard(123, 167, 578, 578, table, table, 2);
}

void loadShipGroupImage(){
	for (int i = 5; i >= 0; i--){
		toTransparentImage(ship[i].getImage());
		setImageSize(ship[i].getX(), ship[i].getY(), ship[i].getWidth(), ship[i].getHeight(), 0, 0, 0);
		if (ship[i].getRotation())
			Counterclockwise_Degree_Rotation(ship[i].getNewX(), ship[i].getNewY());

		setImageSize(ship[i].getNewX(), ship[i].getNewY(), ship[i].getWidth(), ship[i].getHeight(), 0, 1, 0);
		glLoadIdentity();
		gluOrtho2D(0, windowWidth, windowHeight, 0);
	}
}

void moveShipByMouse(){
	if (mouse_down){
		player.initShips();
		for (int i = 0; i < 6; i++)
			if (123 > ship[i].getNewX() || 701 < ship[i].getNewX() || 167 > ship[i].getNewY() || 745 < ship[i].getNewY()){
				ship[i].setReady(false);
			}
			else{
				for (int j = ship[i].getHeadColumn(); j <= ship[i].getBodyColumn(); j++)
					for (int k = ship[i].getHeadRow(); k <= ship[i].getBodyRow(); k++){
						if (ship[i].getRotation())
							player.setShipCell(k, j, ship[i].getLengthWidth());
						else
							player.setShipCell(k, j, ship[i].getLengthHeight());
						ship[i].setReady(true);
					}
			}
	}
}

void drawTestTable(){
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	setFontHeight(50);
	setFontXY(0, 0);

	player.testShipTable(0, 200);
	computer.testShipTable(200, 200);
}
