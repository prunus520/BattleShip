#include "shipPositionFrame.h"

void shipPositionFrame(){
	loadShipImage();
	loadRadarBoardImage();
	loadBackImage();
	useGreenPaint();
	drawCheckerBoard();
	loadShipGroupImage();
	moveShipByMouse();
	drawTestTable();
}

void loadShipImage(){
	if(ship0.isEmpty()){
		ship0.load();
		ship1.load();
		ship2.load();
		ship3.load();
		ship4.load();
		ship5.load();
		IplImage *image[6] = {ship0.getImage(), ship1.getImage(), ship2.getImage(), ship3.getImage(), ship4.getImage(), ship5.getImage()};
		int coordinate[6][2] = {{1108, 186}, {1161, 186}, {1228, 186}, {1100, 280}, {1202, 280}, {1010, 170}};
		float size[6][2] = {{16, 67.2}, {24, 65.6}, {16, 67.2}, {65, 212.5}, {50, 212.5}, {54, 336}};
		int length[6][2] = {{1, 1}, {1, 1}, {1, 1}, {1, 3}, {1, 3}, {1, 5}};
		for(int i = 0; i != 6; ++i){
			ship[i].setImage(image[i]);
			ship[i].setCoordinate(coordinate[i][0], coordinate[i][1]);
			ship[i].setSize(size[i][0], size[i][1]);
			ship[i].setLength(length[i][0], length[i][1]);
		}
		randomComputerShips();
	}
}

void randomComputerShips(){
	srand(time(NULL));
	computer.randomShips();
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
