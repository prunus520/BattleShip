#include "mainInit.h"

Frame frame = MAIN_FRAME;

float windowWidth = 1196 * 1.2, windowHeight = 720 * 1.2;
float scaleX = 1, scaleY = 1;

Mouse mouse;

Image background("image/background.jpg");
Image title("image/title.png");
Image sea("image/sea.jpg");
Image radarBoard("image/radarBoard.jpg");
ShipImage ship[6] = {"image/ship0.png", "image/ship1.png",
										 "image/ship2.png", "image/ship3.png",
										 "image/ship4.png", "image/ship5.png"};
Image back("image/back.png");
Image wave("image/wave.jpg");
Image fire("image/fire.png");

int shipMove = -1;
bool isComputer = true;
bool isPalyerMouseClickedUp = true;

Battleship computer, player;

bool isDebug = false;
