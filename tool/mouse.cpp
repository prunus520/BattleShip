#include "mouse.h"

void Mouse::setMotionCoordinate(int x, int y){
	motion.x = x;
	motion.y = y;
}

int Mouse::getMotionX(){
	return motion.x;
}

int Mouse::getMotionY(){
	return motion.y;
}

void Mouse::setClickCoordinate(int x, int y){
	click.x = x;
	click.y = y;
}

int Mouse::getClickX(){
	return click.x;
}

int Mouse::getClickY(){
	return click.y;
}

void Mouse::setMoveCoordinate(int x, int y){
	move.x = x;
	move.y = y;
}

int Mouse::getMoveX(){
	return move.x;
}

int Mouse::getMoveY(){
	return move.y;
}

void Mouse::setClicked(int state){
	clicked = state;
}

int Mouse::getClicked(){
	return clicked;
}
