#ifndef SHIP_H
#define SHIP_H

#include <GL/glut.h>
#include <opencv/cv.h>

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

class Ship{
	public:
		Ship();
		~Ship();
		void setImage(IplImage*);
		void setCoordinate(GLfloat, GLfloat);
		void setNewCoordinate(GLfloat, GLfloat);
		void setOldCoordinate(GLfloat, GLfloat);
		void setSize(GLfloat, GLfloat);
		void setLength(int, int);
		void setLengthWidth(int);
		void setLengthHeight(int);
		GLfloat getX();
		GLfloat getY();
		GLfloat getNewX();
		GLfloat getNewY();
		GLfloat getOldX();
		GLfloat getOldY();
		GLfloat getWidth();
		GLfloat getHeight();
		GLfloat getRealWidth();
		GLfloat getRealHeight();
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
		IplImage *getImage();
		void setRealWidth(GLfloat);
		void setRealHeight(GLfloat);
	private:
		static int IDCouter;
		int ID;
		IplImage *image = nullptr;
		Size size;
		Size realSize;
		Length length;
		CoordinateGL coordinate;
		CoordinateGL oldCoordinate;
		CoordinateGL newCoordinate;
		Field head = {0, 0};
		Field body = {0, 0};
		bool rotation = false;
		bool ready = false;
};

#endif
