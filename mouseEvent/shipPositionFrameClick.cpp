#include "shipPositionFrameClick.h"

void shipPositionFrameClick(int state, int x, int y){
	moveShip(state, x, y);
	placeShip(state, x, y);
	clickButton(state, x, y);
//	·Æ¹«ÂIÀ»¾É­Pµøµ¡±Y¼ì 
//	checkShipState(state, x, y);
}

void moveShip(int state, int x, int y){
	for (int i = 0; i < 6; i++){
		if (state == 0 && x >= ship[i].getNewX() && x <= ship[i].getNewX() + ship[i].getRealSizeWidth() &&
				y >= ship[i].getNewY() && y <= ship[i].getNewY() + ship[i].getRealSizeHeight()){
			shipMOVE = ship[i].getID();
			break;
		}
	}
}

void placeShip(int state, int x, int y){
	if (shipMOVE != -1){
		if (state == 1 && (ship[shipMOVE].getNewX() < 123 || ship[shipMOVE].getNewX() + ship[shipMOVE].getRealSizeWidth() > 701 ||
											 ship[shipMOVE].getNewY() < 167 || ship[shipMOVE].getNewY() + ship[shipMOVE].getRealSizeHeight() > 745)){
			initShipXY();
		}
		else if (state == 1 && x >= ship[shipMOVE].getNewX() && x <= ship[shipMOVE].getNewX() + ship[shipMOVE].getRealSizeWidth() &&
						 y >= ship[shipMOVE].getNewY() && y <= ship[shipMOVE].getNewY() + ship[shipMOVE].getRealSizeHeight()){
			shipXY(123, 167, 578, 578);
			for (int i = ship[shipMOVE].getHeadColumn(); i <= ship[shipMOVE].getBodyColumn(); i++)
				for (int j = ship[shipMOVE].getHeadRow(); j <= ship[shipMOVE].getBodyRow(); j++)
					if (player.getShipCell(j, i) != 0)
						initShipXY();
					else{
						if (ship[i].getRotation())
							player.setShipCell(j, i, ship[shipMOVE].getLengthWidth());
						else
							player.setShipCell(j, i, ship[shipMOVE].getLengthHeight());
						ship[i].setReady(true);
					}
		}
	}
}

void initShipXY(){
	ship[shipMOVE].setOldPosition(ship[shipMOVE].getX(), ship[shipMOVE].getY());
	ship[shipMOVE].setNewPosition(ship[shipMOVE].getX(), ship[shipMOVE].getY());
	if (ship[shipMOVE].getRotation()){
		transWidthHeight();
		ship[shipMOVE].setRotation(false);
	}
	ship[shipMOVE].setReady(false);
	shipMOVE = -1;
}

void clickButton(int state, int x, int y){
	if (x >= 0 && x <= 100 && y >= 0 && y <= 100){
		glutTimerFunc(200, glint_START_Timer, 1);
		alpha = 0;
		frame = MAIN_FRAME;
		back.release();
		radarBoard.release();
	}
	else if (x >= 1165 && x <= 1315 && y >= 620 && y <= 770){
		int i;
		for (i = 0; i < 6; i++){
			if (ship[i].getReady() == false)
				break;
		}
		if (i == 6){
			frame = BATTLE_FRAME;
			back.release();
			radarBoard.release();
		}
	}
	else if (state == 0 && x >= 960 && x <= 1110 && y >= 620 && y <= 770){
		for (int i = 5; i >= 0; i--){
			shipMOVE = i;
			initShipXY();
		}
		player.initShips();
	}
}

void checkShipState(int state, int x, int y){
	if (state == 0){
		for (int j = ship[shipMOVE].getHeadColumn(); j <= ship[shipMOVE].getBodyColumn(); j++)
			for (int k = ship[shipMOVE].getHeadRow(); k <= ship[shipMOVE].getBodyRow(); k++){
				if (ship[shipMOVE].getRotation())
					player.setShipCell(k, j, 0);
				else
					player.setShipCell(k, j, 0);
				ship[shipMOVE].setReady(false);
			}
	}
}
