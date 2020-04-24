#include "shipPositionFrameMotion.h"

void shipPositionFrameMotion(){
//	¾É­Pclicked¼Æ­È²§±` 
	motionShip();
}

void motionShip(){
	if (frame == SHIP_POSITION_FRAME){
		ship[shipMOVE].setOldShipPosition(ship[shipMOVE].getNewShipPositionX(), ship[shipMOVE].getNewShipPositionY());
		shipMOVE = -1;
	}
}
