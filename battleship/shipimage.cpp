#include "shipimage.h"

ShipImage::ShipImage(const char *imagePath):Image(imagePath){
	ID = IDCouter++;
}

int ShipImage::IDCouter = 0;

int ShipImage::getID(){
	return ID;
}

void ShipImage::setShipSize(GLfloat width, GLfloat height){
	size.width = width;
	size.height = height;
	setShipRealSize(width, height);
}

GLfloat ShipImage::getShipSizeWidth(){
	return size.width;
}

GLfloat ShipImage::getShipSizeHeight(){
	return size.height;
}

void ShipImage::setShipRealSize(GLfloat width, GLfloat height){
	realSize.width = width;
	realSize.height = height;
}

void ShipImage::setShipRealSizeWidth(GLfloat width){
	realSize.width = width;
}

void ShipImage::setShipRealSizeHeight(GLfloat height){
	realSize.height = height;
}

GLfloat ShipImage::getShipRealSizeWidth(){
	return realSize.width;
}

GLfloat ShipImage::getShipRealSizeHeight(){
	return realSize.height;
}

void ShipImage::setShipLength(int width, int height){
	length.width = width;
	length.height = height;
}

void ShipImage::setShipLengthWidth(int width){
	length.width = width;
}

void ShipImage::setShipLengthHeight(int height){
	length.height = height;
}

int ShipImage::getShipLengthWidth(){
	return length.width;
}

int ShipImage::getShipLengthHeight(){
	return length.height;
}

void ShipImage::setShipPosition(GLfloat x, GLfloat y){
	position.x = x;
	position.y = y;
	setNewShipPosition(x, y);
	setOldShipPosition(x, y);
}

GLfloat ShipImage::getShipPositionX(){
	return position.x;
}

GLfloat ShipImage::getShipPositionY(){
	return position.y;
}

void ShipImage::setNewShipPosition(GLfloat x, GLfloat y){
	newPosition.x = x;
	newPosition.y = y;
}

GLfloat ShipImage::getNewShipPositionX(){
	return newPosition.x;
}

GLfloat ShipImage::getNewShipPositionY(){
	return newPosition.y;
}

void ShipImage::setOldShipPosition(GLfloat x, GLfloat y){
	oldPosition.x = x;
	oldPosition.y = y;
}

GLfloat ShipImage::getOldShipPositionX(){
	return oldPosition.x;
}

GLfloat ShipImage::getOldShipPositionY(){
	return oldPosition.y;
}

void ShipImage::changeOldShipPositionByNewShipPosition(){
	setOldShipPosition(newPosition.x, newPosition.y);
}

void ShipImage::initializeOldAndNewShipPositionByShipPosition(){
	setNewShipPosition(position.x, position.y);
	setOldShipPosition(position.x, position.y);
}

bool ShipImage::isShipPositionWithinRange(int x, int y){
	return (x >= newPosition.x && x <= newPosition.x + realSize.width) &&
				 (y >= newPosition.y && y <= newPosition.y + realSize.height);
}

bool ShipImage::isNewShipPositionWithoutRange(int minX, int maxX, int minY, int maxY){
	return (newPosition.x < minX || newPosition.x + realSize.width > maxX) ||
				 (newPosition.y < minY || newPosition.y + realSize.height > maxY);
}

void ShipImage::setShipField(int headRow, int headColumn, int bodyRow, int bodyColumn){
	head.row = headRow;
	head.column = headColumn;
	body.row = bodyRow;
	body.column = bodyColumn;
}

void ShipImage::resetField(){
	setShipField((int)((newPosition.y - 167) / 72.25), (int)((newPosition.x - 123) / 72.25),
											head.row + length.height - 1,
											head.column + length.width - 1);
}

int ShipImage::getShipHeadRow(){
	return head.row;
}

int ShipImage::getShipHeadColumn(){
	return head.column;
}

int ShipImage::getShipBodyRow(){
	return body.row;
}

int ShipImage::getShipBodyColumn(){
	return body.column;
}

void ShipImage::setShipRotation(bool newRotation){
	rotation = newRotation;
}

bool ShipImage::getShipRotation(){
	return rotation;
}

void ShipImage::notShipRotate(){
	rotation = !rotation;
}

bool ShipImage::checkRotationLengthSuccess(){
//	width&height
	return (head.column + length.height - 1 < 8) && (head.row + length.width - 1 < 8);
}

void ShipImage::setShipReady(bool newReady){
	ready = newReady;
}

bool ShipImage::getShipReady(){
	return ready;
}

void ShipImage::notShipReady(){
	ready = !ready;
}
