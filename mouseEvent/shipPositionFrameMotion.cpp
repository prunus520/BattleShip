#include "shipPositionFrameMotion.h"

void shipPositionFrameMotion(){
//	�ɭPclicked�ƭȲ��` 
	motionShip();
}

void motionShip(){
	if (frame == SHIP_POSITION_FRAME && mouse.getMouseClicked() == 1){
		ship[shipMOVE].changeOldShipPositionByNewShipPosition();
		shipMOVE = -1;
	}
}
