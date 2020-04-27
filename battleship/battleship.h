#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <ctime>
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
		void randomHit();
		bool hitSuccess();
		
		void testHitTable(int, int);
		void testBoardTable(int, int);
	private:
		int row = 0, column = 0;
		int board[8][8] = {{0}};
		int hits[2] = {0};
		void hitShips();
		
		bool openAI = false;
		int hitRowByAI = 0;
		int hitColumnByAI = 0;
		int hitDirection = 0;
		int hitNorthOrSouth = 0;
		int hitEastOrWest = 0;
		int hitCount = 0;
		void initializeHitByAI();
		void smartHitByAI();
		void hitDirectionOption();
		void hitWest();
		void randomHitByAI();
		void resetHitField();
};
 
#endif
