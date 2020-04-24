#include "shipPositionFrameClick.h"

void shipPositionFrameClick(int state, int x, int y){
	moveShip(state, x, y);
	placeShip(state, x, y);
	clickButton(state, x, y);
//	·Æ¹«ÂIÀ»¾É­Pµøµ¡±Y¼ì 
	checkShipState(state, x, y);
}

void moveShip(int state, int x, int y){
	for (int i = 0; i < 6; i++){
		if (state == 0 && x >= ship[i].getNewShipPositionX() && x <= ship[i].getNewShipPositionX() + ship[i].getShipRealSizeWidth() &&
				y >= ship[i].getNewShipPositionY() && y <= ship[i].getNewShipPositionY() + ship[i].getShipRealSizeHeight()){
			shipMOVE = ship[i].getID();
			break;
		}
	}
}

void placeShip(int state, int x, int y){
	if (shipMOVE != -1){
		if (state == 1 && ship[shipMOVE].isNewShipPositionWithinRange(123, 701, 167, 745)){
			initShipXY();
		}
		else if (state == 1 && x >= ship[shipMOVE].getNewShipPositionX() && x <= ship[shipMOVE].getNewShipPositionX() + ship[shipMOVE].getShipRealSizeWidth() &&
						 y >= ship[shipMOVE].getNewShipPositionY() && y <= ship[shipMOVE].getNewShipPositionY() + ship[shipMOVE].getShipRealSizeHeight()){
			shipXY(123, 167, 578, 578);
			for (int i = ship[shipMOVE].getShipHeadColumn(); i <= ship[shipMOVE].getShipBodyColumn(); i++)
				for (int j = ship[shipMOVE].getShipHeadRow(); j <= ship[shipMOVE].getShipBodyRow(); j++)
					if (player.getShipCell(j, i) != 0)
						initShipXY();
					else{
						if (ship[i].getShipRotation())
							player.setShipCell(j, i, ship[shipMOVE].getShipLengthWidth());
						else
							player.setShipCell(j, i, ship[shipMOVE].getShipLengthHeight());
						ship[i].setShipReady(true);
					}
		}
	}
}

void initShipXY(){
	ship[shipMOVE].setOldShipPosition(ship[shipMOVE].getShipPositionX(), ship[shipMOVE].getShipPositionY());
	ship[shipMOVE].setNewShipPosition(ship[shipMOVE].getShipPositionX(), ship[shipMOVE].getShipPositionY());
	if (ship[shipMOVE].getShipRotation()){
		transWidthHeight();
		ship[shipMOVE].setShipRotation(false);
	}
	ship[shipMOVE].setShipReady(false);
	shipMOVE = -1;
}

void clickButton(int state, int x, int y){
	if (x >= 0 && x <= 100 && y >= 0 && y <= 100){
		glutTimerFunc(200, glint_START_Timer, 1);
		alpha = 0;
		frame = MAIN_FRAME;
		back.releaseImage();
		radarBoard.releaseImage();
	}
	else if (x >= 1165 && x <= 1315 && y >= 620 && y <= 770){
		int i;
		for (i = 0; i < 6; i++){
			if (ship[i].getShipReady() == false)
				break;
		}
		if (i == 6){
			frame = BATTLE_FRAME;
			back.releaseImage();
			radarBoard.releaseImage();
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
	if (state == 0 && shipMOVE != -1){
		for (int j = ship[shipMOVE].getShipHeadColumn(); j <= ship[shipMOVE].getShipBodyColumn(); j++)
			for (int k = ship[shipMOVE].getShipHeadRow(); k <= ship[shipMOVE].getShipBodyRow(); k++){
				if (ship[shipMOVE].getShipRotation())
					player.setShipCell(k, j, 0);
				else
					player.setShipCell(k, j, 0);
				ship[shipMOVE].setShipReady(false);
			}
	}
}
