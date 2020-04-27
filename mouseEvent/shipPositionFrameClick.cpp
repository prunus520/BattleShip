#include "shipPositionFrameClick.h"

namespace shipPositionFrame{
	void click(int state, int x, int y){
		clickShipID(state, x, y);
		catchAndPlaceShip(state, x, y);
		clickButton(state, x, y);
	}
	
	void clickShipID(int state, int x, int y){
		for (int i = 0; i != 6; ++i){
			if (state == 0 && ship[i].isShipCoordinateWithinRange(x, y)){
				shipMove = ship[i].getID();
				break;
			}
		}
	}
	
	void catchAndPlaceShip(int state, int x, int y){
		if (shipMove != -1){
			ship[shipMove].resetField();
			if (state == 0 && ship[shipMove].isShipCoordinateWithinRange(x, y)){
				clearPlaceShipCell();
			}
			else if (state == 1 && ship[shipMove].isShipCoordinateWithoutRange(123, 701, 167, 745)){
				initializeShipPosition();
			}
			else if (state == 1 && ship[shipMove].isShipCoordinateWithinRange(x, y)){
				ship[shipMove].placeShipInCell(123, 167, 578, 578);
				if(checkPlaceFail()){
					initializeShipPosition();
				}
				else {
					placeShipCell();
				}
			}
		}
	}
	
	void clearPlaceShipCell(){
		for (int row = ship[shipMove].getShipHeadRow(); row <= ship[shipMove].getShipBodyRow(); row++){
			for (int column = ship[shipMove].getShipHeadColumn(); column <= ship[shipMove].getShipBodyColumn(); column++){
				player.setShipCell(row, column, isNull);
			}
		}
		ship[shipMove].setShipReady(false);
	}
	
	void initializeShipPosition(){
		ship[shipMove].initializeShipCoordinate();
		if (ship[shipMove].getShipRotation()){
			ship[shipMove].notShipRotate();
		}
		ship[shipMove].setShipReady(false);
		shipMove = -1;
	}
	
	bool checkPlaceFail(){
		int fail = 0;
		for (int row = ship[shipMove].getShipHeadRow(); row <= ship[shipMove].getShipBodyRow(); row++){
			for (int column = ship[shipMove].getShipHeadColumn(); column <= ship[shipMove].getShipBodyColumn(); column++){
				if (player.getShipCell(row, column) != 0){
					++fail;
				}
			}
		}
		return fail;
	}
	
	void placeShipCell(){
		for (int row = ship[shipMove].getShipHeadRow(); row <= ship[shipMove].getShipBodyRow(); row++){
			for (int column = ship[shipMove].getShipHeadColumn(); column <= ship[shipMove].getShipBodyColumn(); column++){
				player.setShipCell(row, column, isShip);
				ship[shipMove].setShipReady(true);
			}
		}
	}
	
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
			ship[i].initializeShipCoordinate();
			if (ship[i].getShipRotation()){
				ship[i].notShipRotate();
			}
			ship[i].setShipReady(false);
		}
		shipMove = -1;
		player.initShips();
	}
}
