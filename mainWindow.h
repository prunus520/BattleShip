#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "frame/mainFrame.h"
#include "frame/shipPositionFrame.h"
#include "frame/battleFrame.h"

void shipInit();

void windowSet();
void windowEvent();
void WindowSize(int w, int h);
void Display();
void updateFrame();

void MouseButton(int button, int state, int x, int y);
void MouseMove(int x, int y);
void MousePassiveMotion(int x, int y);
void glint_START_Timer(int id);
void transWidthHeight();
void initShipXY();

#endif
