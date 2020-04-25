#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H

#include "../mainInit.h"

namespace battleFrame{
	void battleFrame();
	void loadSeaImage();
	void drawPlayerCheckerBoard();
	void drawComputerCheckerBoard();
	void loadPlayerShipGroupImage();
	void judgePlayerOrComputer();
	void judgeToHit();
	void drawWinOrLoseFont();
}

#endif
