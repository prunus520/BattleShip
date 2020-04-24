#include "shipPositionFrameClick.h"

void shipPositionFrameClick(int state, int x, int y){
	clickedShipID(state, x, y);
	placeShip(state, x, y);
	clickButton(state, x, y);
}

void clickedShipID(int state, int x, int y){
	for (int i = 0; i != 6; ++i){
		if (state == 0 && ship[i].isShipPositionWithinRange(x, y)){
			shipMOVE = ship[i].getID();
			break;
		}
	}
}

void placeShip(int state, int x, int y){
	if (shipMOVE != -1){
		if (state == 1 && ship[shipMOVE].isNewShipPositionWithoutRange(123, 701, 167, 745)){
			initShipPosition();
		}
		else if (state == 1 && ship[shipMOVE].isShipPositionWithinRange(x, y)){
			placeShipInCell(123, 167, 578, 578);
			for (int i = ship[shipMOVE].getShipHeadColumn(); i <= ship[shipMOVE].getShipBodyColumn(); i++){
				for (int j = ship[shipMOVE].getShipHeadRow(); j <= ship[shipMOVE].getShipBodyRow(); j++){
					if (player.getShipCell(j, i) != 0){
						initShipPosition();
					}
					else{
//						width&height
						if (ship[i].getShipRotation()){
							player.setShipCell(j, i, ship[shipMOVE].getShipLengthWidth());
						}
						else {
							player.setShipCell(j, i, ship[shipMOVE].getShipLengthHeight());
						}
						ship[i].setShipReady(true);
					}
				}
			}
		}
	}
}

void initShipPosition(){
	ship[shipMOVE].initializeOldAndNewShipPositionByShipPosition();
	if (ship[shipMOVE].getShipRotation()){
//		width&height
		transWidthHeight();
		ship[shipMOVE].notShipRotate();
	}
	ship[shipMOVE].setShipReady(false);
	shipMOVE = -1;
}

void clickButton(int state, int x, int y){
	if (x >= 0 && x <= 100 && y >= 0 && y <= 100){
		backToMainFrame();
	}
	else if (x >= 1165 && x <= 1315 && y >= 620 && y <= 770){
		goToBattleFrame();
	}
	else if (state == 0 && x >= 960 && x <= 1110 && y >= 620 && y <= 770){
		resetShipsPosition();
}
}

void backToMainFrame(){
	glutTimerFunc(200, glint_START_Timer, 1);
	alpha = 0;
	frame = MAIN_FRAME;
	back.releaseImage();
	radarBoard.releaseImage();
}

void goToBattleFrame(){
	int i;
	for (i = 0; i != 6; ++i){
		if (ship[i].getShipReady() == false)
			break;
	}
	if (i == 6){
		frame = BATTLE_FRAME;
		back.releaseImage();
		radarBoard.releaseImage();
	}
}

void resetShipsPosition(){
	for (int i = 5; i != -1; --i){
		ship[i].initializeOldAndNewShipPositionByShipPosition();
		if (ship[i].getShipRotation()){
	//		width&height
			transWidthHeight();
			ship[i].notShipRotate();
		}
		ship[i].setShipReady(false);
	}
	shipMOVE = -1;
	player.initShips();
}
