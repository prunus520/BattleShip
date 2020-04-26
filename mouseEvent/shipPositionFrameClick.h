#ifndef SHIPPOSITIONFRAMECLICK_H
#define SHIPPOSITIONFRAMECLICK_H

#include "../mainInit.h"

namespace shipPositionFrame{
	void click(int, int, int);
	void clickShipID(int, int, int);
	void placeShip(int, int, int);
	void clearPlaceShipCell();
	void initializeShipPosition();
	bool checkPlaceFail();
	void placeShipCell();
	void clickButton(int, int, int);
	void backToMainFrame();
	void goToBattleFrame();
	void resetShipsPosition();
}

#endif
