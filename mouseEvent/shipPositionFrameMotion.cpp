#include "shipPositionFrameMotion.h"

void shipPositionFrameMotion(){
//	¾É­Pclicked¼Æ­È²§±` 
//	motionShip();
}

void motionShip(){
	if (frame == SHIP_POSITION_FRAME){
		ship[shipMOVE].setOldPosition(ship[shipMOVE].getNewX(), ship[shipMOVE].getNewY());
		shipMOVE = -1;
	}
}
