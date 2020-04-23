#include "shipPositionFrameMove.h"

void shipPositionFrameMove(int x, int y){
	moveShip(x, y);
}

void moveShip(int x, int y){
	if (frame == SHIP_POSITION_FRAME){
		if (shipMOVE != -1 && mouse.clicked == 0){
			ship[shipMOVE].setNewCoordinate(ship[shipMOVE].getOldX() - mouse.click.x + mouse.move.x,
																			ship[shipMOVE].getOldY() - mouse.click.y + mouse.move.y);
			ship[shipMOVE].setField((int)((ship[shipMOVE].getNewY() - 167) / 72.25), (int)((ship[shipMOVE].getNewX() - 123) / 72.25),
																	 ship[shipMOVE].getHeadRow() + ship[shipMOVE].getLengthHeight() - 1,
																	 ship[shipMOVE].getHeadColumn() + ship[shipMOVE].getLengthWidth() - 1);
		}
	}
}
