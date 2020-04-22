#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <GL/glut.h>
#include "image.h"
#include "ship.h"
#include "battleship.h"
#include "font.h"
#include "draw.h"

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
#define battle_ship_alarm_red glColor3f(0.4372, 0.0313, 0.0941)
#define battle_ship_alarm_green glColor3f(0.0941, 0.4372, 0.0313)
#define battle_ship_green glColor3f(0.0941, 0.5372, 0.0313)
#define battle_ship_blue glColor3f(0, 0, 1)

float windowX = 1196 * 1.2, windowY = 720 * 1.2;
float sizeMagn = 1;
bool glint_START = true;
int frame = 1;
int mouseX, mouseY;
int button_mouseX, button_mouseY;
int move_mouseX, move_mouseY;
int pointX = windowX, pointY = 0;

Image background("img//background.jpg");
Image title("img//title.png");
Image reel("img//reel.png");
Image sea("img//sea.jpg");
Image radarBoard("img//radarBoard.jpg");
Image ship0("img//ship0.png");
Image ship1("img//ship1.png");
Image ship2("img//ship2.png");
Image ship3("img//ship3.png");
Image ship4("img//ship4.png");
Image ship5("img//ship5.png");
Image back("img//back.png");
Image wave("img//wave.jpg");
Image fire("img//fire.png");

int mouse_down;
int shipMOVE = -1;
bool player_computer_flag = true;
bool player_computer_sleep = false;
bool palyer_init = false;
bool palyer_down = true;
uchar alpha = 0;

Battleship computer, player;
Ship ship[6];

FILE *pFile;
char buffer[1024];

void shipInit();
void WindowSize(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void KeyboardSpecial(int key, int x, int y);
void MouseButton(int button, int state, int x, int y);
void MouseMove(int x, int y);
void MousePassiveMotion(int x, int y);
void Display();
void Init_one();
void Init_two();
void Init_three();
void glint_START_Timer(int id);
void transWidthHeight();
void shipXY(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
void initShipXY();
void player_computer_sleep_Timer(int id);
void player_computer_flag_Timer(int id);

#endif
