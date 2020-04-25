#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <algorithm>
#include <opencv/cv.h>
#include "../tool/font.h"
#include "../tool/imageTool.h"

#define table 8

class Battleship{
	public:
		Battleship();
		void setRow(int);
		void setColumn(int);
		void setShipCell(int, int, int);
		int getShipCell(int, int);
		int getHitShipCell();
		int getHitCell();
		int getBoardCell();
		void initBoard();
		void initShips();
		void initShots();
		void initHits();
		void randomShips();
		void showHitImage(int, int, IplImage *, IplImage *);
		void checkShots();
		void testShipTable(int, int);
		void testHitTable(int, int);
		void testBoardTable(int, int);
	private:
		int row = 0, column = 0;
		int board[8][8] = {{0}};
		int ships[8][8] = {{0}};
		int shots[8][8] = {{0}};
		int hits[2] = {0};
		bool giveShots();
		void changeBoard();
		int hitShips();
};
 
#endif
