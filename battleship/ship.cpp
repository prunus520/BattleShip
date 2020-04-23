#include "ship.h"

Ship::Ship(const char *imagePath):Image(imagePath){
	ID = IDCouter++;
}

void Ship::setPosition(GLfloat x, GLfloat y){
	position.x = x;
	position.y = y;
	oldPosition.x = x;
	oldPosition.y = y;
	newPosition.x = x;
	newPosition.y = y;
}

void Ship::setNewPosition(GLfloat x, GLfloat y){
	newPosition.x = x;
	newPosition.y = y;
}

void Ship::setOldPosition(GLfloat x, GLfloat y){
	oldPosition.x = x;
	oldPosition.y = y;
}

void Ship::setSizes(GLfloat width, GLfloat height){
	size.width = width;
	size.height = height;
	realSize.width = width;
	realSize.height = height;
}

void Ship::setLength(int width, int height){
	length.width = width;
	length.height = height;
}

void Ship::setLengthWidth(int width){
	length.width = width;
}

void Ship::setLengthHeight(int height){
	length.height = height;
}

GLfloat Ship::getX(){
	return position.x;
}

GLfloat Ship::getY(){
	return position.y;
}

GLfloat Ship::getNewX(){
	return newPosition.x;
}

GLfloat Ship::getNewY(){
	return newPosition.y;
}

GLfloat Ship::getOldX(){
	return oldPosition.x;
}

GLfloat Ship::getOldY(){
	return oldPosition.y;
}

GLfloat Ship::getSizeWidth(){
	return size.width;
}

GLfloat Ship::getSizeHeight(){
	return size.height;
}

GLfloat Ship::getRealSizeWidth(){
	return realSize.width;
}

GLfloat Ship::getRealSizeHeight(){
	return realSize.height;
}

int Ship::getHeadRow(){
	return head.row;
}

int Ship::getHeadColumn(){
	return head.column;
}

int Ship::getBodyRow(){
	return body.row;
}

int Ship::getBodyColumn(){
	return body.column;
}

bool Ship::getRotation(){
	return rotation;
}

int Ship::getLengthWidth(){
	return length.width;
}

int Ship::getLengthHeight(){
	return length.height;
}

void Ship::setReady(bool newReady){
	ready = newReady;
}

void Ship::setRotation(bool newRotation){
	rotation = newRotation;
}

int Ship::getID(){
	return ID;
}

bool Ship::getReady(){
	return ready;
}

void Ship::setField(int headRow, int headColumn, int bodyRow, int bodyColumn){
	head.row = headRow;
	head.column = headColumn;
	body.row = bodyRow;
	body.column = bodyColumn;
}

void Ship::setRealSizeWidth(GLfloat width){
	realSize.width = width;
}

void Ship::setRealSizeHeight(GLfloat height){
	realSize.height = height;
}

int Ship::IDCouter = 0;
