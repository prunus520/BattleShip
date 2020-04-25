#ifndef SHIPPOSITIONFRAMERIGHTCLICK_H
#define SHIPPOSITIONFRAMERIGHTCLICK_H

#include "../mainInit.h"

namespace shipPositionFrame{
	void rightClick(int, int, int);
	void rightClickShipID(int, int, int);
	void rotateShipDirection(int, int, int);
	bool checkRotationSuccess();
	bool checkRotationArrayIsZero(int, int);
	void rotatedShip(int, int, int);
	void clearShipCellBeforeRotation(int, int, int);
	void rotateShipBoard();
}

#endif
