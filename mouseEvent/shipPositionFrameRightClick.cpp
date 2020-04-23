#include "shipPositionFrameRightClick.h"

void shipPositionFrameRightClick(int state, int x, int y){
	rotateShip(state, x, y);
}

void rotateShip(int state, int x, int y){
	if (frame == SHIP_POSITION_FRAME){
		for (int i = 0; i < 6; i++){
			if (state == 0 && x >= ship[i].getNewX() && x <= ship[i].getNewX() + ship[i].getRealSizeWidth() &&
					y >= ship[i].getNewY() && y <= ship[i].getNewY() + ship[i].getRealSizeHeight()){
				shipMOVE = ship[i].getID();
				break;
			}
		}
		for (int i = 0; i < 6; i++){
			if (state == 0 && x >= ship[i].getNewX() && x <= ship[i].getNewX() + ship[i].getRealSizeWidth() &&
					y >= ship[i].getNewY() && y <= ship[i].getNewY() + ship[i].getRealSizeHeight()){
				if (ship[i].getX() != ship[i].getNewX() && ship[i].getX() != ship[i].getNewX() &&
						ship[i].getY() != ship[i].getNewY() && ship[i].getY() != ship[i].getNewY())
					shipMOVE = ship[i].getID();
				for (int i = ship[shipMOVE].getHeadColumn(); i <= ship[shipMOVE].getBodyColumn(); i++)
					for (int j = ship[shipMOVE].getHeadRow(); j <= ship[shipMOVE].getBodyRow(); j++){
						if (ship[shipMOVE].getRotation())
							player.setShipCell(j, i, 0);
						else
							player.setShipCell(j, i, 0);
						ship[shipMOVE].setReady(false);
						if (player.getShipCell(i, j) == 0){
							if (ship[shipMOVE].getRotation()){
								ship[shipMOVE].setRotation(false);
								transWidthHeight();
								if (ship[shipMOVE].getNewX() < 123 || ship[shipMOVE].getNewX() + ship[shipMOVE].getRealSizeWidth() > 701 ||
										ship[shipMOVE].getNewY() < 167 || ship[shipMOVE].getNewY() + ship[shipMOVE].getRealSizeHeight() > 745){
									ship[shipMOVE].setRotation(true);
									transWidthHeight();
								}
							}
							else{
								ship[shipMOVE].setRotation(true);
								transWidthHeight();
								if (ship[shipMOVE].getNewX() < 123 || ship[shipMOVE].getNewX() + ship[shipMOVE].getRealSizeWidth() > 701 ||
										ship[shipMOVE].getNewY() < 167 || ship[shipMOVE].getNewY() + ship[shipMOVE].getRealSizeHeight() > 745){
									ship[shipMOVE].setRotation(false);
									transWidthHeight();
								}
							}
							if (ship[shipMOVE].getRotation())
								player.setShipCell(j, i, ship[shipMOVE].getLengthWidth());
							else
								player.setShipCell(j, i, ship[shipMOVE].getLengthHeight());
							ship[shipMOVE].setReady(true);
						}
					}
				ship[shipMOVE].setField((int)((ship[shipMOVE].getNewY() - 167) / 72.25), (int)((ship[shipMOVE].getNewX() - 123) / 72.25),
																			 ship[shipMOVE].getHeadRow() + ship[shipMOVE].getLengthHeight() - 1,
																			 ship[shipMOVE].getHeadColumn() + ship[shipMOVE].getLengthWidth() - 1);
				shipXY(123, 167, 578, 578);
				shipMOVE = -1;
				break;
			}
		}
	}
}
