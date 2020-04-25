#include "shipPositionFrameRightClick.h"

void shipPositionFrameRightClick(int state, int x, int y){
	rotateShip(state, x, y);
}

void rotateShip(int state, int x, int y){
	if (frame == SHIP_POSITION_FRAME){
		rightClickedShipID(state, x, y);
		rotateShipDirection(state, x, y);
	}
}

void rightClickedShipID(int state, int x, int y){
	for (int i = 0; i != 6; ++i){
		if (state == 0 && ship[i].isShipPositionWithinRange(x, y)){
			shipMOVE = ship[i].getID();
			break;
		}
	}
}

void rotateShipDirection(int state, int x, int y){
	if(state == 0 && !ship[shipMOVE].isNewShipPositionWithoutRange(123, 701, 167, 745)){
		if(checkRotationSuccess()){
			rotatedShip(state, x, y);
		}
		shipMOVE = -1;
	}
}

bool checkRotationSuccess(){
	int fail = -1;
	if(ship[shipMOVE].checkRotationLengthSuccess()){
		for (int row = 0; row <= ship[shipMOVE].getShipBodyRow() - ship[shipMOVE].getShipHeadRow(); ++row){
			for (int column = 0; column <= ship[shipMOVE].getShipBodyColumn() - ship[shipMOVE].getShipHeadColumn(); ++column){
				if(checkRotationArrayIsZero(row, column)){
					++fail;
				}
			}
		}
	}
	return !fail;
}

bool checkRotationArrayIsZero(int row, int column){
	return player.getShipCell(column + ship[shipMOVE].getShipHeadRow(), row + ship[shipMOVE].getShipHeadColumn());
}

void rotatedShip(int state, int x, int y){
	ship[shipMOVE].notShipRotate();
	clearShipCellBeforeRotation(state, x, y);
	ship[shipMOVE].resetField();
	rotateShipBoard();
	ship[shipMOVE].placeShipInCell(123, 167, 578, 578);
}

void clearShipCellBeforeRotation(int state, int x, int y){
	for (int row = ship[shipMOVE].getShipHeadRow(); row <= ship[shipMOVE].getShipBodyRow(); ++row){
		for (int column = ship[shipMOVE].getShipHeadColumn(); column <= ship[shipMOVE].getShipBodyColumn(); ++column){
			player.setShipCell(row, column, 0);
		}
	}
}

void rotateShipBoard(){
	for (int row = ship[shipMOVE].getShipHeadRow(); row <= ship[shipMOVE].getShipBodyRow(); ++row){
		for (int column = ship[shipMOVE].getShipHeadColumn(); column <= ship[shipMOVE].getShipBodyColumn(); ++column){
			player.setShipCell(row, column, ship[shipMOVE].getShipLengthHeight());
		}
	}
}
