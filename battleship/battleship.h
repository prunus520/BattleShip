#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <time.h>
#include <algorithm>
#include "../tool/font.h"
#include "../tool/imageTool.h"

#define table 8

#define isNull 0
#define isShip 1
#define isHit 2
#define isnHit 3

class Battleship{
	public:
		Battleship();
		void setRow(int);
		void setColumn(int);
		
		void setShipCell(int, int, int);
		int getShipCell(int, int);
		void initShips();
		void randomShips();
		
		int getHitShipCell();
		int getHitCell();
		void initHits();
		
		int getBoardCell(int, int);
		void initBoard();
		
		bool isLose();
		bool hitSuccess();
		
		void testHitTable(int, int);
		void testBoardTable(int, int);
	private:
		int row = 0, column = 0;
		int board[8][8] = {{0}};
		int hits[2] = {0};
		void hitShips();
};
 
#endif
