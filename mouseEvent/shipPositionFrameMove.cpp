#include "shipPositionFrameMove.h"

void shipPositionFrameMove(int x, int y){
	moveShip(x, y);
}

void moveShip(int x, int y){
	if (frame == SHIP_POSITION_FRAME && mouse.getMouseButton() == GLUT_LEFT_BUTTON){
		if (shipMOVE != -1 && mouse.getMouseClicked() == 0){
			ship[shipMOVE].setNewShipPosition(ship[shipMOVE].getOldShipPositionX() - mouse.getMouseClickX() + x,
																			ship[shipMOVE].getOldShipPositionY() - mouse.getMouseClickY() + y);
			
			ship[shipMOVE].resetField();
		}
	}
}
