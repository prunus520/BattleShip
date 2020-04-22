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

//			battle_ship_color
#define battle_ship_alarm_red glColor3f(0.4372, 0.0313, 0.0941)
#define battle_ship_alarm_green glColor3f(0.0941, 0.4372, 0.0313)
#define battle_ship_green glColor3f(0.0941, 0.5372, 0.0313)
#define battle_ship_blue glColor3f(0, 0, 1)

float windowWidth = 1196 * 1.2, windowHeight = 720 * 1.2;
float sizeMagn = 1;
bool glint_START = true;
int frame = 1;
int mouseX, mouseY;
int button_mouseX, button_mouseY;
int move_mouseX, move_mouseY;
int pointX = windowWidth, pointY = 0;

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

void windowSet();
void shipInit();
void WindowSize(int w, int h);
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
