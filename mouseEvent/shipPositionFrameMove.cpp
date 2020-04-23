#include "shipPositionFrameMove.h"

void shipPositionFrameMove(int x, int y){
	moveShip(x, y);
}

void moveShip(int x, int y){
	if (frame == SHIP_POSITION_FRAME){
		if (shipMOVE != -1 && mouse.getClicked() == 0){
			ship[shipMOVE].setNewCoordinate(ship[shipMOVE].getOldX() - mouse.getClickX() + mouse.getMoveX(),
																			ship[shipMOVE].getOldY() - mouse.getClickY() + mouse.getMoveY());
			ship[shipMOVE].setField((int)((ship[shipMOVE].getNewY() - 167) / 72.25), (int)((ship[shipMOVE].getNewX() - 123) / 72.25),
																	 ship[shipMOVE].getHeadRow() + ship[shipMOVE].getLengthHeight() - 1,
																	 ship[shipMOVE].getHeadColumn() + ship[shipMOVE].getLengthWidth() - 1);
		}
	}
}
