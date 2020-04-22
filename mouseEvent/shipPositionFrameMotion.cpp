#include "shipPositionFrameMotion.h"

void shipPositionFrameMotion(int x, int y){
	motionShip(x, y);
}

void motionShip(int x, int y){
	if (frame == SHIP_POSITION_FRAME){
		ship[shipMOVE].setOldCoordinate(ship[shipMOVE].getNewX(), ship[shipMOVE].getNewY());
		shipMOVE = -1;
	}
}
