#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "frame/mainFrame.h"
#include "frame/shipPositionFrame.h"
#include "frame/battleFrame.h"
#include "mouseEvent/mainFrameClick.h"
#include "mouseEvent/shipPositionFrameClick.h"
#include "mouseEvent/battleFrameClick.h"
#include "mouseEvent/shipPositionFrameRightClick.h"
#include "mouseEvent/shipPositionFrameMove.h"
#include "mouseEvent/shipPositionFrameMotion.h"

void createGlutWindow();
int centerWindowX();
int centerWindowY();

void catchGlutEvent();

void catchWindowSizeEvent();
void catchWindowSize(int, int);
void setScale(int, int);
void changeWindowSize(int, int);

void catchDisplayEvent();
void catchDisplay();
void resetCoordinates();
void clearCanvas();
void switchFrame();
void drawTest();
void updateCanvas();

void catchMouseEvent();
void catchMouseClick(int, int, int, int);
void setMouseClickCoordinates(int, int, int);
void catchMouseButton(int, int, int, int);
void switchFrameClick(int, int, int);
void catchMouseMove(int, int);
void setMouseMoveCoordinates(int, int);
void catchMousePassiveMotion(int, int);
void setMouseMotionCoordinates(int, int);

bool isDebug = false;
void catchKeyboardEvent();
void catchKeyboard(unsigned char, int, int);

#endif
