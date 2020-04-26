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
}

GLfloat ShipImage::getShipSizeWidth(){
	return size.width;
}

GLfloat ShipImage::getShipSizeHeight(){
	return size.height;
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
	setShipCoordinate(x, y);
	setPlaceShipCoordinate(x, y);
}

GLfloat ShipImage::getShipPositionX(){
	return position.x;
}

GLfloat ShipImage::getShipPositionY(){
	return position.y;
}

void ShipImage::setShipCoordinate(GLfloat x, GLfloat y){
	coordinate.x = x;
	coordinate.y = y;
}

GLfloat ShipImage::getShipCoordinateX(){
	return coordinate.x;
}

GLfloat ShipImage::getShipCoordinateY(){
	return coordinate.y;
}

void ShipImage::setPlaceShipCoordinate(GLfloat x, GLfloat y){
	placeCoordinate.x = x;
	placeCoordinate.y = y;
}

GLfloat ShipImage::getPlaceShipCoordinateX(){
	return placeCoordinate.x;
}

GLfloat ShipImage::getPlaceShipCoordinateY(){
	return placeCoordinate.y;
}

void ShipImage::changePlaceShipCoordinateByShipCoordinate(){
	setPlaceShipCoordinate(coordinate.x, coordinate.y);
}

void ShipImage::initializeShipCoordinate(){
	setShipCoordinate(position.x, position.y);
	setPlaceShipCoordinate(position.x, position.y);
}

bool ShipImage::isShipCoordinateWithinRange(int x, int y){
	return (x >= coordinate.x && x <= coordinate.x + getRotateSizeHeight()) &&
				 (y >= coordinate.y && y <= coordinate.y + getRotateSizeWidth());
}

bool ShipImage::isShipCoordinateWithoutRange(int minX, int maxX, int minY, int maxY){
	return (coordinate.x < minX || coordinate.x + getRotateSizeHeight() > maxX + (maxX - minX) / 16) ||
				 (coordinate.y < minY || coordinate.y + getRotateSizeWidth() > maxY + (maxX - minX) / 16);
}

void ShipImage::placeShipInCell(GLfloat x, GLfloat y, GLfloat width, GLfloat height){
	setShipCoordinate(x + head.column * width / 8 + (getRotateLenghtHeight() * width / 8 - getRotateSizeHeight()) / 2,
										 y + head.row * height / 8 + (getRotateLenghtWidth() * height / 8 - getRotateSizeWidth()) / 2);
}

void ShipImage::loadShipCoordinate(){
		setImageSize(coordinate.x, coordinate.y, size.width, size.height);
}

void ShipImage::setShipField(int headRow, int headColumn, int bodyRow, int bodyColumn){
	head.row = headRow;
	head.column = headColumn;
	body.row = bodyRow;
	body.column = bodyColumn;
}

void ShipImage::resetField(){
	setShipField(round((coordinate.y - 72.25 / 4 - 167) / 72.25), round((coordinate.x - 72.25 / 4 - 123) / 72.25),
											head.row + getRotateLenghtWidth() - 1,
											head.column + getRotateLenghtHeight() - 1);
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

void ShipImage::rotateShipImage(){
	counterclockwiseDegreeRotation(coordinate.x, coordinate.y);
}

bool ShipImage::checkRotationLengthSuccess(){
	return (head.column + getRotateLenghtWidth() - 1 < 8) && (head.row + getRotateLenghtHeight() - 1 < 8);
}

GLfloat ShipImage::getRotateSizeWidth(){
	return rotation ? size.width: size.height;
}

GLfloat ShipImage::getRotateSizeHeight(){
	return rotation ? size.height: size.width;
}

GLfloat ShipImage::getRotateLenghtWidth(){
	return rotation ? length.width: length.height;
}

GLfloat ShipImage::getRotateLenghtHeight(){
	return rotation ? length.height: length.width;
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
