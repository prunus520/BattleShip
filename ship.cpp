#include "ship.h"

Ship::Ship(){
	ID = IDCouter++;
}

void Ship::setImage(IplImage *srcImage){
	image = srcImage;
}

void Ship::setCoordinate(GLfloat x, GLfloat y){
	coordinate.x = x;
	coordinate.y = y;
	oldCoordinate.x = x;
	oldCoordinate.y = y;
	newCoordinate.x = x;
	newCoordinate.y = y;
}

void Ship::setNewCoordinate(GLfloat x, GLfloat y){
	newCoordinate.x = x;
	newCoordinate.y = y;
}

void Ship::setOldCoordinate(GLfloat x, GLfloat y){
	oldCoordinate.x = x;
	oldCoordinate.y = y;
}

void Ship::setSize(GLfloat width, GLfloat height){
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
	return coordinate.x;
}

GLfloat Ship::getY(){
	return coordinate.y;
}

GLfloat Ship::getNewX(){
	return newCoordinate.x;
}

GLfloat Ship::getNewY(){
	return newCoordinate.y;
}

GLfloat Ship::getOldX(){
	return oldCoordinate.x;
}

GLfloat Ship::getOldY(){
	return oldCoordinate.y;
}

GLfloat Ship::getWidth(){
	return size.width;
}

GLfloat Ship::getHeight(){
	return size.height;
}

GLfloat Ship::getRealWidth(){
	return realSize.width;
}

GLfloat Ship::getRealHeight(){
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

IplImage *Ship::getImage(){
	return image;
}

void Ship::setRealWidth(GLfloat width){
	realSize.width = width;
}

void Ship::setRealHeight(GLfloat height){
	realSize.height = height;
}

int Ship::IDCouter = 0;
