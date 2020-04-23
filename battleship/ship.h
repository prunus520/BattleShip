#ifndef SHIP_H
#define SHIP_H

#include <GL/glut.h>
#include <opencv/cv.h>
#include "../tool/image.h"

struct CoordinateGL{
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

class Ship:public Image{
	public:
		Ship(const char*);
		void setPosition(GLfloat, GLfloat);
		void setNewPosition(GLfloat, GLfloat);
		void setOldPosition(GLfloat, GLfloat);
		void setSizes(GLfloat, GLfloat);
		void setLength(int, int);
		void setLengthWidth(int);
		void setLengthHeight(int);
		GLfloat getX();
		GLfloat getY();
		GLfloat getNewX();
		GLfloat getNewY();
		GLfloat getOldX();
		GLfloat getOldY();
		GLfloat getSizeWidth();
		GLfloat getSizeHeight();
		GLfloat getRealSizeWidth();
		GLfloat getRealSizeHeight();
		int getHeadRow();
		int getHeadColumn();
		int getBodyRow();
		int getBodyColumn();
		bool getRotation();
		int getLengthWidth();
		int getLengthHeight();
		void setReady(bool);
		void setRotation(bool);
		int getID();
		bool getReady();
		void setField(int, int, int, int);
		void setRealSizeWidth(GLfloat);
		void setRealSizeHeight(GLfloat);
	private:
		static int IDCouter;
		int ID;
		Size size;
		Size realSize;
		Length length;
		CoordinateGL position;
		CoordinateGL oldPosition;
		CoordinateGL newPosition;
		Field head = {0, 0};
		Field body = {0, 0};
		bool rotation = false;
		bool ready = false;
};

#endif
