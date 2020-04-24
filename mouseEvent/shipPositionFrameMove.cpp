#include "shipPositionFrameMove.h"

void shipPositionFrameMove(int x, int y){
	moveShip(x, y);
}

void moveShip(int x, int y){
	if (frame == SHIP_POSITION_FRAME){
		if (shipMOVE != -1 && mouse.getClicked() == 0){
			ship[shipMOVE].setNewShipPosition(ship[shipMOVE].getOldShipPositionX() - mouse.getClickX() + mouse.getMoveX(),
																			ship[shipMOVE].getOldShipPositionY() - mouse.getClickY() + mouse.getMoveY());
			ship[shipMOVE].setShipField((int)((ship[shipMOVE].getNewShipPositionY() - 167) / 72.25), (int)((ship[shipMOVE].getNewShipPositionX() - 123) / 72.25),
																	 ship[shipMOVE].getShipHeadRow() + ship[shipMOVE].getShipLengthHeight() - 1,
																	 ship[shipMOVE].getShipHeadColumn() + ship[shipMOVE].getShipLengthWidth() - 1);
		}
	}
}
