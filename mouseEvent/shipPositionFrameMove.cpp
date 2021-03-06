#include "shipPositionFrameMove.h"

namespace shipPositionFrame{
	void move(int x, int y){
		moveShip(x, y);
	}
	
	void moveShip(int x, int y){
		if (frame == SHIP_POSITION_FRAME && mouse.getMouseButton() == GLUT_LEFT_BUTTON){
			if (shipMove != -1 && mouse.getMouseState() == 0){
				ship[shipMove].setShipCoordinate(ship[shipMove].getPlaceShipCoordinateX() - mouse.getMouseClickX() + x,
																				 ship[shipMove].getPlaceShipCoordinateY() - mouse.getMouseClickY() + y);
				ship[shipMove].resetField();
			}
		}
	}
}
