#include "shipPositionFrameMotion.h"

void shipPositionFrameMotion(){
//	�ɭPclicked�ƭȲ��` 
//	motionShip();
}

void motionShip(){
	if (frame == SHIP_POSITION_FRAME){
		ship[shipMOVE].setOldPosition(ship[shipMOVE].getNewX(), ship[shipMOVE].getNewY());
		shipMOVE = -1;
	}
}
