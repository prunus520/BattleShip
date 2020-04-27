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
	board[newRow][newColumn] = newValue;
}

int Battleship::getShipCell(int newRow, int newColumn){
	return board[newRow][newColumn];
}

int Battleship::getHitShipCell(){
	return hits[0];
}

int Battleship::getHitCell(){
	return hits[1];
}

int Battleship::getBoardCell(int newRow, int newColumn){
	return board[newRow][newColumn];
}

void Battleship::initBoard(){
	std::fill(&board[0][0], &board[8][0], isNull);
}

void Battleship::initShips(){
	initBoard();
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
	srand(time(NULL));
	for (int shipType = 0; shipType != 3; ++shipType){
		for (int shipCount = shipType; shipCount != -1; --shipCount){
			randomRotation = rand() % 2;
			while (true){
				randomRow = rand() % (9 - shipLength[shipType]);
				randomColumn = rand() % (9 - shipLength[shipType]);
				successCount = 0;
				for(int index = 0; index != shipLength[shipType]; ++index){
					shipIndex = randomRotation == true ? (randomRow + index) * 8 + randomColumn : randomRow * 8 + randomColumn + index;
					if(*(*board + shipIndex) == isNull){
						++successCount;
					}else{
						continue;
					}
				}
				if(successCount == shipLength[shipType]){
					for(int index = 0; index != shipLength[shipType]; ++index){
						shipIndex = randomRotation == true ? (randomRow + index) * 8 + randomColumn : randomRow * 8 + randomColumn + index;
						*(*board + shipIndex) = isShip;
					}
					break;
				}
			}
		}
	}
}

bool Battleship::isLose(){
	return hits[0] == 14;
}

void Battleship::randomHit(){
	srand(time(NULL));
	initializeHitByAI();
	smartHitByAI();
	if (!openAI){
		randomHitByAI();
	}
}

void Battleship::initializeHitByAI(){
	if (board[row][column] == isHit && openAI == false){
		openAI = true;
		hitRowByAI = row;
		hitColumnByAI = column;
		hitDirection = rand() % 4;
		hitNorthOrSouth = 0;
		hitEastOrWest = 0;
		hitCount = 0;
	}
}

void Battleship::smartHitByAI(){
	if (openAI){
		while (!hitSuccess()){
			if(hitNorthOrSouth == 2 && hitEastOrWest == 2){
				openAI = false;
				break;
			}
			hitDirectionOption();
		}
		++hitCount;
	}
}

void Battleship::hitDirectionOption(){
	switch (hitDirection){
		case 0:
			++row;
			break;
		case 1:
			--row;
			break;
		case 2:
			++column;
			break;
		case 3:
			--column;
			break;
	}
	if ((hitDirection < 2 ? hitNorthOrSouth : hitEastOrWest) == 2) {
		resetHitField();
		hitDirection = rand() % 2 + (hitDirection < 2 ? 2 : 0);
	}
	else if (row < 0 || row > 7 || column < 0 || column > 7 || board[row][column] == isHit || board[row][column] == isnHit ||
			(hitDirection < 2 ? (hitDirection == 0 ? board[row - 1][column] : board[row + 1][column]) :
			(hitDirection == 2 ? board[row][column - 1] : board[row][column + 1])) == isnHit){
		resetHitField();
		hitDirection < 2 ? ++hitNorthOrSouth : ++hitEastOrWest;
		hitDirection = !(hitDirection % 2) + (hitDirection < 2 ? 0 : 2);
	}
}

void Battleship::resetHitField(){
	row = hitRowByAI;
	column = hitColumnByAI;
	hitCount = 1;
}

void Battleship::randomHitByAI(){
	do {
		row = rand() % 8;
		column = rand() % 8;
	}
	while (!hitSuccess());
}

bool Battleship::hitSuccess(){
	if (board[row][column] == isShip){
		board[row][column] = isHit;
		++hits[0];
		return 1;
	}
	else if (board[row][column] == isNull){
		board[row][column] = isnHit;
		++hits[1];
		return 1;
	}
	return 0;
}

void Battleship::hitShips(){
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glColor3f(0, 0, 0);
	setFontHeight(65);
	setFontXY(270, 100);
	if (board[row][column] == isHit){
		if (row >= 800){
			printFont("You hit a ship with the shot ( %d , %d )", row + 1, column + 1);
		}
		else {
			printFont("Hit a ship with the shot ( %d , %d )", row + 1, column + 1);
		}
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
	}
}

void Battleship::testHitTable(int x, int y){
	glColor3f(1, 1, 0);
	setFontHeight(20);
	setFontXY(x, y);
	printFont("hit:\n");
	printFont("%d/%d ", getHitShipCell(), getHitCell());
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
