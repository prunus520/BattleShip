#include "mouse.h"

void Mouse::setMouseMotionCoordinate(int x, int y){
	motion.x = x;
	motion.y = y;
}

int Mouse::getMouseMotionX(){
	return motion.x;
}

int Mouse::getMouseMotionY(){
	return motion.y;
}

void Mouse::setMouseMoveCoordinate(int x, int y){
	move.x = x;
	move.y = y;
}

int Mouse::getMouseMoveX(){
	return move.x;
}

int Mouse::getMouseMoveY(){
	return move.y;
}

void Mouse::setMouseClickCoordinate(int x, int y){
	click.x = x;
	click.y = y;
}

int Mouse::getMouseClickX(){
	return click.x;
}

int Mouse::getMouseClickY(){
	return click.y;
}

bool Mouse::isMouseClickRangeCoordinate(int minX, int maxX, int minY, int maxY){
	return (click.x >= minX && click.x <= maxX) && (click.y >= minY && click.y <= maxY);
}

void Mouse::setMouseState(int newState){
	state = newState;
}

int Mouse::getMouseState(){
	return state;
}

void Mouse::setMouseButton(int newButton){
	button = newButton;
}

int Mouse::getMouseButton(){
	return button;
}
