#include "shipPositionFrameRightClick.h"

namespace shipPositionFrame{
	void rightClick(int state, int x, int y){
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
			if (state == 0 && ship[i].isShipCoordinateWithinRange(x, y)){
				shipMove = ship[i].getID();
				break;
			}
		}
	}
	
	void rotateShipDirection(int state, int x, int y){
		if(state == 0 && !ship[shipMove].isShipCoordinateWithoutRange(123, 701, 167, 745)){
			if(checkRotationSuccess()){
				rotatedShip(state, x, y);
			}
			shipMove = -1;
		}
	}
	
	bool checkRotationSuccess(){
		int fail = -1;
		if(ship[shipMove].checkRotationLengthSuccess()){
			for (int row = 0; row <= ship[shipMove].getShipBodyRow() - ship[shipMove].getShipHeadRow(); ++row){
				for (int column = 0; column <= ship[shipMove].getShipBodyColumn() - ship[shipMove].getShipHeadColumn(); ++column){
					if(checkRotationArrayIsZero(row, column)){
						++fail;
					}
				}
			}
		}
		return !fail;
	}
	
	bool checkRotationArrayIsZero(int row, int column){
		return player.getShipCell(column + ship[shipMove].getShipHeadRow(), row + ship[shipMove].getShipHeadColumn());
	}
	
	void rotatedShip(int state, int x, int y){
		ship[shipMove].notShipRotate();
		clearShipCellBeforeRotation(state, x, y);
		ship[shipMove].resetField();
		rotateShipBoard();
		ship[shipMove].placeShipInCell(123, 167, 578, 578);
	}
	
	void clearShipCellBeforeRotation(int state, int x, int y){
		for (int row = ship[shipMove].getShipHeadRow(); row <= ship[shipMove].getShipBodyRow(); ++row){
			for (int column = ship[shipMove].getShipHeadColumn(); column <= ship[shipMove].getShipBodyColumn(); ++column){
				player.setShipCell(row, column, 0);
			}
		}
	}
	
	void rotateShipBoard(){
		for (int row = ship[shipMove].getShipHeadRow(); row <= ship[shipMove].getShipBodyRow(); ++row){
			for (int column = ship[shipMove].getShipHeadColumn(); column <= ship[shipMove].getShipBodyColumn(); ++column){
				player.setShipCell(row, column, ship[shipMove].getShipLengthHeight());
			}
		}
	}
}
