#ifndef SHIPIMAGE_H
#define SHIPIMAGE_H

#include "../library/include/GL/glut.h"
#include "../library/include/opencv/cv.h"
#include "../tool/image.h"
#include "../tool/draw.h"

class ShipImage:public Image{
	struct Coordinate{
		GLfloat x;
		GLfloat y;
	};
	
	struct Size{
		GLfloat width;
		GLfloat height;
	};
	
	struct Field{
		int row;
		int column;
	};
	
	struct Length{
		int width;
		int height;
	};

	public:
		ShipImage(const char *);
		
		int getID();
		
		void setShipSize(GLfloat, GLfloat);
		GLfloat getShipSizeWidth();
		GLfloat getShipSizeHeight();
		
		void setShipLength(int, int);
		void setShipLengthWidth(int);
		void setShipLengthHeight(int);
		int getShipLengthWidth();
		int getShipLengthHeight();
		
		void setShipPosition(GLfloat, GLfloat);
		GLfloat getShipPositionX();
		GLfloat getShipPositionY();
		
		void setShipCoordinate(GLfloat, GLfloat);
		GLfloat getShipCoordinateX();
		GLfloat getShipCoordinateY();
		
		void setPlaceShipCoordinate(GLfloat, GLfloat);
		GLfloat getPlaceShipCoordinateX();
		GLfloat getPlaceShipCoordinateY();
		
		void changePlaceShipCoordinateByShipCoordinate();
		void initializeShipCoordinate();
		bool isShipCoordinateWithinRange(int, int);
		bool isShipCoordinateWithoutRange(int, int, int, int);
		void placeShipInCell(GLfloat, GLfloat, GLfloat, GLfloat);
		void loadShipCoordinate();
		
		void setShipField(int, int, int, int);
		void resetField();
		int getShipHeadRow();
		int getShipHeadColumn();
		int getShipBodyRow();
		int getShipBodyColumn();
		
		void setShipRotation(bool);
		bool getShipRotation();
		void notShipRotate();
		void rotateShipImage();
		bool checkRotationLengthSuccess();
		GLfloat getRotateSizeWidth();
		GLfloat getRotateSizeHeight();
		GLfloat getRotateLenghtWidth();
		GLfloat getRotateLenghtHeight();
		
		void setShipReady(bool);
		bool getShipReady();
		void notShipReady();
		
	private:
		static int IDCouter;
		int ID;
		Size size;
		Length length;
		Coordinate position;
		Coordinate coordinate;
		Coordinate placeCoordinate;
		Field head = {0, 0};
		Field body = {0, 0};
		bool rotation = false;
		bool ready = false;
};

#endif
