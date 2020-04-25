#ifndef SHIPPOSITIONFRAME_H
#define SHIPPOSITIONFRAME_H

#include "../mainInit.h"

namespace shipPositionFrame{
	void display();
	
	extern bool isRandomShip;
	void randomComputerShips();
	
	void loadImage();
	void loadRadarBoardImage();
	void loadBackImage();
	void loadShipsGroupImage();
	
	void setShipsData();
	void loadShipsImage();
	void loadShipShadowImage(int);
	void loadGreenShipImage(int);
	void initializeCoordinate();
	
	void drawCheckerBoard();
	void useGreenPaint();
}

#endif
