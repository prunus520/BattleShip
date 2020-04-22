#ifndef MAININIT_H
#define MAININIT_H

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <GL/glut.h>
#include "tool/image.h"
#include "battleship/ship.h"
#include "battleship/battleship.h"
#include "tool/font.h"
#include "tool/draw.h"

#define table 8

//			battle_ship_color
#define battle_ship_alarm_red glColor3f(0.4372, 0.0313, 0.0941)
#define battle_ship_alarm_green glColor3f(0.0941, 0.4372, 0.0313)

enum Frame{MAIN_FRAME, SHIP_POSITION_FRAME, BATTLE_FRAME};
extern Frame frame;

extern float windowWidth, windowHeight;
extern float sizeMagn;
extern bool glint_START;
extern int mouseX, mouseY;
extern int button_mouseX, button_mouseY;
extern int move_mouseX, move_mouseY;
extern int pointX, pointY;

extern Image background;
extern Image title;
extern Image sea;
extern Image radarBoard;
extern Image ship0;
extern Image ship1;
extern Image ship2;
extern Image ship3;
extern Image ship4;
extern Image ship5;
extern Image back;
extern Image wave;
extern Image fire;

extern int mouse_down;
extern int shipMOVE;
extern bool player_computer_flag;
extern bool player_computer_sleep;
extern bool palyer_init;
extern bool palyer_down;
extern uchar alpha;

extern Battleship computer, player;
extern Ship ship[6];

void shipXY(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
void player_computer_sleep_Timer(int id);
void player_computer_flag_Timer(int id);

#endif
