#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <algorithm>
#include <opencv/cv.h>
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
		void showHitImage(int, int, IplImage *, IplImage *);
		
		int getBoardCell();
		void initBoard();
		
		void initShots();
		void checkShots();
		bool isLose();
		
		void testHitTable(int, int);
		void testBoardTable(int, int);
	private:
		int row = 0, column = 0;
		int board[8][8] = {{0}};
		int shots[8][8] = {{0}};
		int hits[2] = {0};
		bool giveShots();
		void changeBoard();
		int hitShips();
};
 
#endif
