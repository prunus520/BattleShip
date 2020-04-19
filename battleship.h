#ifndef BATTLESHIP_H
#define BATTLESHIP_H
 
class Battleship{
	public:
		Battleship();
		void setRow(int);
		void setColumn(int);
		void setShipCell(int, int, int);
		int getShipCell(int, int);
		int getHitCell(int);
		int getBoardCell();
		void initBoard();
		void initShips();
		void initShots();
		void initHits();
		void randomShips();
		void showBoard(int, int, IplImage *, IplImage *);
		void checkShots();
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
