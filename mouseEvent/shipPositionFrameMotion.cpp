#include "shipPositionFrameMotion.h"

void shipPositionFrameMotion(){
//	�ɭPclicked�ƭȲ��` 
	motionShip();
}

void motionShip(){
	if (frame == SHIP_POSITION_FRAME){
		ship[shipMOVE].changeOldShipPositionByNewShipPosition();
		shipMOVE = -1;
	}
}
