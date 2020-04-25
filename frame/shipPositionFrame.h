#ifndef SHIPPOSITIONFRAME_H
#define SHIPPOSITIONFRAME_H

#include "../mainInit.h"

namespace shipPositionFrame{
	extern bool isRandomShip;
	
	void display();
	void randomComputerShips();
	
	void loadImage();
	void loadRadarBoardImage();
	void loadBackImage();
	void loadShipGroupImage();
	
	void initializeShips();
	void loadShipsImage();
	void loadShipShadowImage(int);
	void loadGreenShipImage(int);
	void initializeCoordinate();
	
	void drawCheckerBoard();
	void useGreenPaint();
}

#endif
