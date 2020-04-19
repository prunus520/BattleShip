//			battle_ship.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <GL/glut.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#define table 8

#define ESC 27

//			gult secial key
#define F1 GLUT_KEY_F1
#define F2 GLUT_KEY_F2
#define F3 GLUT_KEY_F3
#define F4 GLUT_KEY_F4
#define F5 GLUT_KEY_F5
#define F6 GLUT_KEY_F6
#define F7 GLUT_KEY_F7
#define F8 GLUT_KEY_F8
#define F9 GLUT_KEY_F9
#define F10 GLUT_KEY_F10
#define F11 GLUT_KEY_F11
#define F12 GLUT_KEY_F12
#define LEFT GLUT_KEY_LEFT
#define UP GLUT_KEY_UP
#define RIGHT GLUT_KEY_RIGHT
#define DOWN GLUT_KEY_DOWN
#define PGUP GLUT_KEY_PAGE_UP
#define PGDN GLUT_KEY_PAGE_DOWN
#define HOME GLUT_KEY_HOME
#define END GLUT_KEY_END
#define INSERT GLUT_KEY_INSERT

//			battle_ship_color
#define battle_ship_alarm_red glColor3f( 0.4372, 0.0313, 0.0941 )
#define battle_ship_alarm_green glColor3f( 0.0941, 0.4372, 0.0313 )
#define battle_ship_green glColor3f( 0.0941, 0.5372, 0.0313 )
#define battle_ship_blue glColor3f( 0, 0, 1 )


struct Coordinate{
	GLfloat x;
	GLfloat y;
};

struct ShipSize{
	GLfloat width;
	GLfloat height;
};

struct ShipCoordinate{
	int HeadRow;
	int HeadColumn;
	int BodyRow;
	int BodyColumn;
};

struct ShipLength{
	int width;
	int height;
};

struct Ship{
	int ID;
	IplImage *imagePath;
	ShipSize shipSize;
	ShipSize real_shipSize;
	ShipLength shipLength;
	Coordinate XY;
	Coordinate oldXY;
	Coordinate newXY;
	ShipCoordinate ShipRowCol;
	bool rotation;
	bool ready;
};


//			Battle Ship Main
void startBoard( int board[][table], int shot[][table] );
void startShips( int ships[][table] );
void showBoard( int board[][table], int x, int y, IplImage *hit, IplImage *nohit );
bool giveShot( int row, int column, int shot[][table], int board[][table] );
int hitShip( int row, int column, int shot[][table], int ships[][table] );
void changeBoard( int row, int column, int shot[][table], int ships[][table], int board[][table] );
void initShip( int ships[][table] );


//			font.cpp
int Print_Font( const char *format, ... );
void setFontHeight( int Height );
void setCreateFont( );
void setFontXY( GLfloat x, GLfloat y );
void setFontFace( const char *FaceName );


//			image.cpp
void Image( IplImage *img );
void Image_Transparent( IplImage *img, uchar red = 255, uchar green = 255, uchar blue = 255, uchar alpha = 255 );
void Image_Size( GLfloat x1, GLfloat y1, GLfloat width, GLfloat height, GLfloat red = 1,GLfloat green = 1,GLfloat blue = 1 );


//			draw.cpp
void line( GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat LineWidth = 1 );
void Hollow_Square( GLfloat x1, GLfloat y1, GLfloat width, GLfloat height, GLfloat LineWidth = 1 );
void Solid_Square( GLfloat x1, GLfloat y1, GLfloat width, GLfloat height );
void checkerboard( GLfloat x, GLfloat y, GLfloat width, GLfloat height, int width_cell, int height_cell, GLfloat LineWidth = 1 );
void Counterclockwise_Degree_Rotation( GLfloat x, GLfloat y );
