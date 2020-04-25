#include "shipPositionFrameClick.h"

namespace shipPositionFrameClick{
	void shipPositionFrameClick(int state, int x, int y){
		clickShip(state, x, y);
		placeShip(state, x, y);
		clickButton(state, x, y);
	}
	
	void clickShip(int state, int x, int y){
		clickShipID(state, x, y);
		clearPlaceShipCell(state, x, y);
	}
	
	void clickShipID(int state, int x, int y){
		for (int i = 0; i != 6; ++i){
			if (state == 0 && ship[i].isShipPositionWithinRange(x, y)){
				shipMOVE = ship[i].getID();
				break;
			}
		}
	}
	
	void clearPlaceShipCell(int state, int x, int y){
		if (shipMOVE != -1 && state == 0 && ship[shipMOVE].isShipPositionWithinRange(x, y)){
			ship[shipMOVE].setNewShipPosition(ship[shipMOVE].getOldShipPositionX() - mouse.getMouseClickX() + x,
																				ship[shipMOVE].getOldShipPositionY() - mouse.getMouseClickY() + y);
			ship[shipMOVE].resetField();
			for (int row = ship[shipMOVE].getShipHeadRow(); row <= ship[shipMOVE].getShipBodyRow(); row++){
				for (int column = ship[shipMOVE].getShipHeadColumn(); column <= ship[shipMOVE].getShipBodyColumn(); column++){
					player.setShipCell(row, column, 0);
				}
			}
		}
	}
	
	void placeShip(int state, int x, int y){
		if (shipMOVE != -1){
			if (state == 1 && ship[shipMOVE].isNewShipPositionWithoutRange(123, 701, 167, 745)){
				initializeShipPosition();
			}
			else if (state == 1 && ship[shipMOVE].isShipPositionWithinRange(x, y)){
				ship[shipMOVE].placeShipInCell(123, 167, 578, 578);
				for (int row = ship[shipMOVE].getShipHeadRow(); row <= ship[shipMOVE].getShipBodyRow(); row++){
					for (int column = ship[shipMOVE].getShipHeadColumn(); column <= ship[shipMOVE].getShipBodyColumn(); column++){
						if (player.getShipCell(row, column) != 0){
							initializeShipPosition();
						}
						else {
							player.setShipCell(row, column, ship[shipMOVE].getShipLengthHeight());
							ship[shipMOVE].setShipReady(true);
						}
					}
				}
			}
		}
	}
	
	void initializeShipPosition(){
		ship[shipMOVE].initializeOldAndNewShipPositionByShipPosition();
		if (ship[shipMOVE].getShipRotation()){
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
				ship[i].notShipRotate();
			}
			ship[i].setShipReady(false);
		}
		shipMOVE = -1;
		player.initShips();
	}
}
