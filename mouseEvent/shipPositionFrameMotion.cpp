#include "shipPositionFrameMotion.h"

void shipPositionFrameMotion(){
//	¾É­Pclicked¼Æ­È²§±` 
	motionShip();
}

void motionShip(){
	if (frame == SHIP_POSITION_FRAME && mouse.getMouseClicked() == 1){
		ship[shipMOVE].changeOldShipPositionByNewShipPosition();
		shipMOVE = -1;
	}
}
