#include "shipPositionFrameMove.h"

void shipPositionFrameMove(int x, int y){
	moveShip(x, y);
}

void moveShip(int x, int y){
	if (frame == SHIP_POSITION_FRAME){
		if (shipMOVE != -1 && mouse.getMouseClicked() == 0){
			ship[shipMOVE].setNewShipPosition(ship[shipMOVE].getOldShipPositionX() - mouse.getMouseClickX() + mouse.getMouseMoveX(),
																			ship[shipMOVE].getOldShipPositionY() - mouse.getMouseClickY() + mouse.getMouseMoveY());
			ship[shipMOVE].resetField();
		}
	}
}
