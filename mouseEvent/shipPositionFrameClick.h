#ifndef SHIPPOSITIONFRAMECLICK_H
#define SHIPPOSITIONFRAMECLICK_H

#include "../mainInit.h"

void shipPositionFrameClick(int state, int x, int y);
void moveShip(int state, int x, int y);
void placeShip(int state, int x, int y);
void initShipXY();
void clickButton(int state, int x, int y);
void checkShipState(int state, int x, int y);

#endif
