#include "shipPositionFrameClick.h"

namespace shipPositionFrame{
	void click(int state, int x, int y){
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
			if (state == 0 && ship[i].isShipCoordinateWithinRange(x, y)){
				shipMove = ship[i].getID();
				break;
			}
		}
	}
	
	void clearPlaceShipCell(int state, int x, int y){
		if (shipMove != -1 && state == 0 && ship[shipMove].isShipCoordinateWithinRange(x, y)){
			ship[shipMove].resetField();
			for (int row = ship[shipMove].getShipHeadRow(); row <= ship[shipMove].getShipBodyRow(); row++){
				for (int column = ship[shipMove].getShipHeadColumn(); column <= ship[shipMove].getShipBodyColumn(); column++){
					player.setShipCell(row, column, 0);
				}
			}
		}
	}
	
	void placeShip(int state, int x, int y){
		if (shipMove != -1){
			ship[shipMove].resetField();
			if (state == 1 && ship[shipMove].isShipCoordinateWithoutRange(123, 701, 167, 745)){
				initializeShipPosition();
			}
			else if (state == 1 && ship[shipMove].isShipCoordinateWithinRange(x, y)){
				ship[shipMove].placeShipInCell(123, 167, 578, 578);
				for (int row = ship[shipMove].getShipHeadRow(); row <= ship[shipMove].getShipBodyRow(); row++){
					for (int column = ship[shipMove].getShipHeadColumn(); column <= ship[shipMove].getShipBodyColumn(); column++){
						if (player.getShipCell(row, column) != 0){
							initializeShipPosition();
						}
						else {
							player.setShipCell(row, column, ship[shipMove].getShipLengthHeight());
							ship[shipMove].setShipReady(true);
						}
					}
				}
			}
		}
	}
	
	void initializeShipPosition(){
		ship[shipMove].initializeOldAndNewShipCoordinateByShipPosition();
		if (ship[shipMove].getShipRotation()){
			ship[shipMove].notShipRotate();
		}
		ship[shipMove].setShipReady(false);
		shipMove = -1;
	}
	////////////////////////
	void clickButton(int state, int x, int y){
		if (mouse.isMouseClickRangeCoordinate(0, 100, 0, 100)){
			backToMainFrame();
		}
		else if (mouse.isMouseClickRangeCoordinate(1165, 1315, 620, 770)){
			goToBattleFrame();
		}
		else if (state == 0 && mouse.isMouseClickRangeCoordinate(960, 1110, 620, 770)){
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
			ship[i].initializeOldAndNewShipCoordinateByShipPosition();
			if (ship[i].getShipRotation()){
				ship[i].notShipRotate();
			}
			ship[i].setShipReady(false);
		}
		shipMove = -1;
		player.initShips();
	}
}
