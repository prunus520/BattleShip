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

void windowSet();
void windowEvent();
void WindowSize(int w, int h);
void Display();
void updateFrame();

void MouseClick(int button, int state, int x, int y);
void MouseMove(int x, int y);
void MousePassiveMotion(int x, int y);

#endif
