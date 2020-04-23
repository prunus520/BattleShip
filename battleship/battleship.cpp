#include "battleship.h"

Battleship::Battleship(){
	initBoard();
}

void Battleship::setRow(int newRow){
	row = newRow;
}

void Battleship::setColumn(int newColumn){
	column = newColumn;
}

void Battleship::setShipCell(int newRow, int newColumn, int newValue){
	ships[newRow][newColumn] = newValue;
}

int Battleship::getShipCell(int newRow, int newColumn){
	return ships[newRow][newColumn];
}

int Battleship::getHitCell(int index){
	return hits[index];
}

int Battleship::getBoardCell(){
	return board[row][column];
}

void Battleship::initBoard(){
	std::fill(&board[0][0], &board[8][0], -1);
}

void Battleship::initShips(){
	std::fill(&ships[0][0], &ships[8][0], 0);
}

void Battleship::initShots(){
	std::fill(&shots[0][0], &shots[8][0], 0);
}

void Battleship::initHits(){
	std::fill(&hits[0], &hits[2], 0);
}

void Battleship::randomShips(){
	initShips();
	int shipLength[3] = {5, 3, 1};
	int randomRow, randomColumn, randomRotation;
	int successCount;
	int shipIndex;
	for (int shipType = 0; shipType != 3; ++shipType){
		for (int shipCount = shipType; shipCount != -1; --shipCount){
			randomRotation = rand() % 2;
			while (true){
				randomRow = rand() % (9 - shipLength[shipType]);
				randomColumn = rand() % (9 - shipLength[shipType]);
				successCount = 0;
				for(int index = 0; index != shipLength[shipType]; ++index){
					shipIndex = randomRotation == true ? (randomRow + index) * 8 + randomColumn : randomRow * 8 + randomColumn + index;
					if(*(*ships + shipIndex) == 0){
						++successCount;
					}else{
						continue;
					}
				}
				if(successCount == shipLength[shipType]){
					for(int index = 0; index != shipLength[shipType]; ++index){
						shipIndex = randomRotation == true ? (randomRow + index) * 8 + randomColumn : randomRow * 8 + randomColumn + index;
						*(*ships + shipIndex) = shipLength[shipType];
					}
					break;
				}
			}
		}
	}
}

void Battleship::showBoard(int x, int y, IplImage *hit, IplImage *nohit){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (board[i][j] == 0){
				showImage(nohit);
				setImageSize(x + 1.5 + j * 67.5, y + 1.5 + i * 67.5, 64.5, 64.5);
			}
			else if (board[i][j] == 1){
				toTransparentImage(hit);
				setImageSize(x + 1.5 + j * 67.5, y + 1.5 + i * 67.5, 64.5, 64.5);
			}
		}
	}
}

void Battleship::checkShots(){
	if (giveShots()){
		changeBoard();
		if (board[row][column] == 1)
			hits[0]++;
		else if (board[row][column] == 0)
			hits[1]++;
	}
}

bool Battleship::giveShots(){
	if (board[row][column] == 0 || board[row][column] == 1){
		return false;
	}
	else{
		shots[row][column] = 1;
		return true;
	}
}

void Battleship::changeBoard(){
	if (hitShips() == 1)
		board[row][column] = 1;
	else
		board[row][column] = 0;
}

int Battleship::hitShips(){
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glColor3f(0, 0, 0);
	setFontHeight(65);
	setFontXY(270, 100);
	if (shots[row][column] == ships[row][column]){
		if (row >= 800)
			printFont("You hit a small ship with the shot ( %d , %d )", row + 1, column + 1);
		else
			printFont("Hit a small ship with the shot ( %d , %d )", row + 1, column + 1);
	}
	else if (shots[row][column] + 2 == ships[row][column]){
		if (row >= 800)
			printFont("You hit a medium ship with the shot (%d , %d )", row + 1, column + 1);
		else
			printFont("Hit a medium ship with the shot (%d , %d )", row + 1, column + 1);
	}
	else if (shots[row][column] + 4 == ships[row][column]){
		if (row >= 800)
			printFont("You hit a large ship with the shot ( %d , %d )", row + 1, column + 1);
		else
			printFont("Hit a large ship with the shot ( %d , %d )", row + 1, column + 1);
	}
	else{
		if (row >= 800){
			setFontXY(600, 100);
			printFont("Oops !");
		}
		else{
			setFontXY(350, 100);
			printFont("Where did you shoot ? Noob !");
		}
		return 0;
	}
	return 1;
}

void Battleship::testShipTable(int x, int y){
	glColor3f(1, 1, 0);
	setFontHeight(20);
	setFontXY(x, y);
	printFont("ship:\n");
	for (int i = 0; i < table; i++){
		for (int j = 0; j < table; j++){
			printFont("%d ", getShipCell(i, j));
		}
		printFont("\n");
	}
}

void Battleship::testHitTable(int x, int y){
	glColor3f(1, 1, 0);
	setFontHeight(20);
	setFontXY(x, y);
	printFont("hit:\n");
	for (int i = 0; i < 2; i++){
			printFont("%d ", getHitCell(i));
		printFont("\n");
	}
}

void Battleship::testBoardTable(int x, int y){
	glColor3f(1, 1, 0);
	setFontHeight(20);
	setFontXY(x, y);
	printFont("board:\n");
	for (int i = 0; i < table; i++){
		for (int j = 0; j < table; j++){
			printFont("%d ", board[i][j]);
		}
		printFont("\n");
	}
}
