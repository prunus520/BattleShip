#ifndef MAININIT_H
#define MAININIT_H

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <GL/glut.h>
#include "tool/image.h"
#include "battleship/shipimage.h"
#include "battleship/battleship.h"
#include "tool/font.h"
#include "tool/draw.h"
#include "tool/mouse.h"

#define table 8

//			battle_ship_color
#define battle_ship_alarm_red glColor3f(0.4372, 0.0313, 0.0941)
#define battle_ship_alarm_green glColor3f(0.0941, 0.4372, 0.0313)

enum Frame{MAIN_FRAME, SHIP_POSITION_FRAME, BATTLE_FRAME};
extern Frame frame;

extern float windowWidth, windowHeight;
extern float scaleX, scaleY;

extern Mouse mouse;

extern Image background;
extern Image title;
extern Image sea;
extern Image radarBoard;
extern ShipImage ship[6];
extern Image back;
extern Image wave;
extern Image fire;

extern int shipMOVE;
extern bool player_computer_flag;
extern bool player_computer_sleep;
extern bool palyer_init;
extern bool palyer_down;

extern Battleship computer, player;

void player_computer_sleep_Timer(int);
void player_computer_flag_Timer(int);
bool checkRangeX(int, int, int);
bool checkRangeY(int, int, int);

#endif
