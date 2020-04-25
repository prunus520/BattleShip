#include "shipPositionFrameMotion.h"

namespace shipPositionFrameMotion{
	void shipPositionFrameMotion(){
		motionShip();
	}
	
	void motionShip(){
		if (frame == SHIP_POSITION_FRAME && shipMOVE != -1){
			ship[shipMOVE].changeOldShipPositionByNewShipPosition();
			shipMOVE = -1;
		}
	}
}
