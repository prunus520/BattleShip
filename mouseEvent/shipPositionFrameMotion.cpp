#include "shipPositionFrameMotion.h"

namespace shipPositionFrame{
	void motion(){
		motionShip();
	}
	
	void motionShip(){
		if (frame == SHIP_POSITION_FRAME && shipMove != -1){
			ship[shipMove].changeOldShipCoordinateByShipCoordinate();
			shipMove = -1;
		}
	}
}
