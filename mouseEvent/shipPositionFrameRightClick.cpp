#include "shipPositionFrameRightClick.h"

void shipPositionFrameRightClick(int state, int x, int y){
	rotateShip(state, x, y);
}

void rotateShip(int state, int x, int y){
	if (frame == SHIP_POSITION_FRAME){
		for (int i = 0; i < 6; i++){
			if (state == 0 && x >= ship[i].getNewShipPositionX() && x <= ship[i].getNewShipPositionX() + ship[i].getShipRealSizeWidth() &&
					y >= ship[i].getNewShipPositionY() && y <= ship[i].getNewShipPositionY() + ship[i].getShipRealSizeHeight()){
				shipMOVE = ship[i].getID();
				break;
			}
		}
		for (int i = 0; i < 6; i++){
			if (state == 0 && x >= ship[i].getNewShipPositionX() && x <= ship[i].getNewShipPositionX() + ship[i].getShipRealSizeWidth() &&
					y >= ship[i].getNewShipPositionY() && y <= ship[i].getNewShipPositionY() + ship[i].getShipRealSizeHeight()){
				if (ship[i].getShipPositionX() != ship[i].getNewShipPositionX() && ship[i].getShipPositionX() != ship[i].getNewShipPositionX() &&
						ship[i].getShipPositionY() != ship[i].getNewShipPositionY() && ship[i].getShipPositionY() != ship[i].getNewShipPositionY())
					shipMOVE = ship[i].getID();
				for (int i = ship[shipMOVE].getShipHeadColumn(); i <= ship[shipMOVE].getShipBodyColumn(); i++)
					for (int j = ship[shipMOVE].getShipHeadRow(); j <= ship[shipMOVE].getShipBodyRow(); j++){
						if (ship[shipMOVE].getShipRotation())
							player.setShipCell(j, i, 0);
						else
							player.setShipCell(j, i, 0);
						ship[shipMOVE].setShipReady(false);
						if (player.getShipCell(i, j) == 0){
							if (ship[shipMOVE].getShipRotation()){
								ship[shipMOVE].setShipRotation(false);
								transWidthHeight();
								if (ship[shipMOVE].getNewShipPositionX() < 123 || ship[shipMOVE].getNewShipPositionX() + ship[shipMOVE].getShipRealSizeWidth() > 701 ||
										ship[shipMOVE].getNewShipPositionY() < 167 || ship[shipMOVE].getNewShipPositionY() + ship[shipMOVE].getShipRealSizeHeight() > 745){
									ship[shipMOVE].setShipRotation(true);
									transWidthHeight();
								}
							}
							else{
								ship[shipMOVE].setShipRotation(true);
								transWidthHeight();
								if (ship[shipMOVE].getNewShipPositionX() < 123 || ship[shipMOVE].getNewShipPositionX() + ship[shipMOVE].getShipRealSizeWidth() > 701 ||
										ship[shipMOVE].getNewShipPositionY() < 167 || ship[shipMOVE].getNewShipPositionY() + ship[shipMOVE].getShipRealSizeHeight() > 745){
									ship[shipMOVE].setShipRotation(false);
									transWidthHeight();
								}
							}
							if (ship[shipMOVE].getShipRotation())
								player.setShipCell(j, i, ship[shipMOVE].getShipLengthWidth());
							else
								player.setShipCell(j, i, ship[shipMOVE].getShipLengthHeight());
							ship[shipMOVE].setShipReady(true);
						}
					}
				ship[shipMOVE].setShipField((int)((ship[shipMOVE].getNewShipPositionY() - 167) / 72.25), (int)((ship[shipMOVE].getNewShipPositionX() - 123) / 72.25),
																			 ship[shipMOVE].getShipHeadRow() + ship[shipMOVE].getShipLengthHeight() - 1,
																			 ship[shipMOVE].getShipHeadColumn() + ship[shipMOVE].getShipLengthWidth() - 1);
				shipXY(123, 167, 578, 578);
				shipMOVE = -1;
				break;
			}
		}
	}
}
