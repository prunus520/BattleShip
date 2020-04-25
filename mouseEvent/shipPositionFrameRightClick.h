#ifndef SHIPPOSITIONFRAMERIGHTCLICK_H
#define SHIPPOSITIONFRAMERIGHTCLICK_H

#include "../mainInit.h"

void shipPositionFrameRightClick(int, int, int);
void rotateShip(int, int, int);
void rightClickedShipID(int, int, int);
void rotateShipDirection(int, int, int);
bool checkRotationSuccess();
bool checkRotationArrayIsZero(int, int);
void rotatedShip(int, int, int);
void clearShipCellBeforeRotation(int, int, int);
void rotateShipBoard();

#endif
