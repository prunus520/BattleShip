#ifndef SHIPIMAGE_H
#define SHIPIMAGE_H

#include <GL/glut.h>
#include <opencv/cv.h>
#include "../tool/image.h"
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
		ShipImage(const char*);
		
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
		
		void setNewShipPosition(GLfloat, GLfloat);
		GLfloat getNewShipPositionX();
		GLfloat getNewShipPositionY();
		
		void setOldShipPosition(GLfloat, GLfloat);
		GLfloat getOldShipPositionX();
		GLfloat getOldShipPositionY();
		
		void changeOldShipPositionByNewShipPosition();
		void initializeOldAndNewShipPositionByShipPosition();
		bool isShipPositionWithinRange(int, int);
		bool isNewShipPositionWithoutRange(int, int, int, int);
		void placeShipInCell(GLfloat, GLfloat, GLfloat, GLfloat);
		
		void setShipField(int, int, int, int);
		void resetField();
		int getShipHeadRow();
		int getShipHeadColumn();
		int getShipBodyRow();
		int getShipBodyColumn();
		
		void setShipRotation(bool);
		bool getShipRotation();
		void notShipRotate();
		bool checkRotationLengthSuccess();
		
		void setShipReady(bool);
		bool getShipReady();
		void notShipReady();
		
	private:
		static int IDCouter;
		int ID;
		Size size;
		Length length;
		Coordinate position;
		Coordinate newPosition;
		Coordinate oldPosition;
		Field head = {0, 0};
		Field body = {0, 0};
		bool rotation = false;
		bool ready = false;
};

#endif
