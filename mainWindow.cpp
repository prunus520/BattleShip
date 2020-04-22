#include "mainWindow.h"

void shipInit(){
	ship0.load();
	ship1.load();
	ship2.load();
	ship3.load();
	ship4.load();
	ship5.load();
	IplImage *image[6] = {ship0.getImage(), ship1.getImage(), ship2.getImage(), ship3.getImage(), ship4.getImage(), ship5.getImage()};
	int coordinate[6][2] = {{1108, 186}, {1161, 186}, {1228, 186}, {1100, 280}, {1202, 280}, {1010, 170}};
	float size[6][2] = {{16, 67.2}, {24, 65.6}, {16, 67.2}, {65, 212.5}, {50, 212.5}, {54, 336}};
	int length[6][2] = {{1, 1}, {1, 1}, {1, 1}, {1, 3}, {1, 3}, {1, 5}};
	for(int i = 0; i != 6; ++i){
		ship[i].setImage(image[i]);
		ship[i].setCoordinate(coordinate[i][0], coordinate[i][1]);
		ship[i].setSize(size[i][0], size[i][1]);
		ship[i].setLength(length[i][0], length[i][1]);
	}
}

void windowSet(){
	int screenWidth = GetSystemMetrics(SM_CXSCREEN),
			screenHeight = GetSystemMetrics(SM_CYSCREEN),
			centerPositionX = (screenWidth - windowWidth) / 2,
			centerPositionY = (screenHeight - windowHeight) / 2;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(centerPositionX, centerPositionY);
	glutCreateWindow("Battle Ship");
}

void windowEvent(){
	glutReshapeFunc(WindowSize);
	glutDisplayFunc(Display);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMove);
	glutPassiveMotionFunc(MousePassiveMotion);
	glutTimerFunc(200, glint_START_Timer, 1);

	glutMainLoop();
}

void WindowSize(int w, int h){
	sizeMagn *= h / windowHeight;
	windowWidth = w;
	windowHeight = h;
	glViewport(0, 0, w, h);
}

void Display(){
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, windowHeight, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch (frame){
		case MAIN_FRAME:
			mainFrame();
			break;
		case SHIP_POSITION_FRAME:
			shipPositionFrame();
			break;
		case BATTLE_FRAME:
			battleFrame();
			break;
	}
	updateFrame();
}

void updateFrame(){
	glutPostRedisplay();
	glutSwapBuffers();
}

void MouseButton(int button, int state, int x, int y){
	mouse_down = state;
	button_mouseX = x;
	button_mouseY = y;
	switch (button){
	case GLUT_LEFT_BUTTON:
		switch (frame){
			case MAIN_FRAME:
				if (x >= 637.6 && x <= 807.6 && y >= 674 && y <= 729){
					frame = SHIP_POSITION_FRAME;
					background.release();
					title.release();
				}
				break;
			case SHIP_POSITION_FRAME:
				for (int i = 0; i < 6; i++){
					if (state == 0 && x >= ship[i].getNewX() && x <= ship[i].getNewX() + ship[i].getRealWidth() &&
							y >= ship[i].getNewY() && y <= ship[i].getNewY() + ship[i].getRealHeight()){
						shipMOVE = ship[i].getID();
						break;
					}
				}
				if (shipMOVE != -1){
					if (state == 1 && (ship[shipMOVE].getNewX() < 123 || ship[shipMOVE].getNewX() + ship[shipMOVE].getRealWidth() > 701 ||
														 ship[shipMOVE].getNewY() < 167 || ship[shipMOVE].getNewY() + ship[shipMOVE].getRealHeight() > 745)){
						initShipXY();
					}
					else if (state == 1 && x >= ship[shipMOVE].getNewX() && x <= ship[shipMOVE].getNewX() + ship[shipMOVE].getRealWidth() &&
									 y >= ship[shipMOVE].getNewY() && y <= ship[shipMOVE].getNewY() + ship[shipMOVE].getRealHeight()){
						shipXY(123, 167, 578, 578);
						for (int i = ship[shipMOVE].getHeadColumn(); i <= ship[shipMOVE].getBodyColumn(); i++)
							for (int j = ship[shipMOVE].getHeadRow(); j <= ship[shipMOVE].getBodyRow(); j++)
								if (player.getShipCell(j, i) != 0)
									initShipXY();
								else{
									if (ship[i].getRotation())
										player.setShipCell(j, i, ship[shipMOVE].getLengthWidth());
									else
										player.setShipCell(j, i, ship[shipMOVE].getLengthHeight());
									ship[i].setReady(true);
								}
					}
				}
				if (x >= 0 && x <= 100 && y >= 0 && y <= 100){
					glutTimerFunc(200, glint_START_Timer, 1);
					alpha = 0;
					frame = MAIN_FRAME;
					back.release();
					radarBoard.release();
				}
				else if (x >= 1165 && x <= 1315 && y >= 620 && y <= 770){
					int i;
					for (i = 0; i < 6; i++){
						if (ship[i].getReady() == false)
							break;
					}
					if (i == 6){
						frame = BATTLE_FRAME;
						back.release();
						radarBoard.release();
					}
				}
				else if (state == 0 && x >= 960 && x <= 1110 && y >= 620 && y <= 770){
					for (int i = 5; i >= 0; i--){
						shipMOVE = i;
						initShipXY();
					}
					player.initShips();
				}
				if (state == 0){
					for (int j = ship[shipMOVE].getHeadColumn(); j <= ship[shipMOVE].getBodyColumn(); j++)
						for (int k = ship[shipMOVE].getHeadRow(); k <= ship[shipMOVE].getBodyRow(); k++){
							if (ship[shipMOVE].getRotation())
								player.setShipCell(k, j, 0);
							else
								player.setShipCell(k, j, 0);
							ship[shipMOVE].setReady(false);
						}
				}
				break;
			case BATTLE_FRAME:
				if (state == 1 && button_mouseX >= 800 && button_mouseX <= 1340 &&
						button_mouseY >= 310 && button_mouseY <= 850 && player_computer_sleep && palyer_down){
					computer.setRow((button_mouseY - 310) / 67.5);
					computer.setColumn((button_mouseX - 800) / 67.5);
					player_computer_flag = true;
					palyer_init = true;
				}
				break;
			}
			break;
		case GLUT_RIGHT_BUTTON:
			if (frame == SHIP_POSITION_FRAME){
				for (int i = 0; i < 6; i++){
					if (state == 0 && x >= ship[i].getNewX() && x <= ship[i].getNewX() + ship[i].getRealWidth() &&
							y >= ship[i].getNewY() && y <= ship[i].getNewY() + ship[i].getRealHeight()){
						shipMOVE = ship[i].getID();
						break;
					}
				}
				for (int i = 0; i < 6; i++){
					if (state == 0 && x >= ship[i].getNewX() && x <= ship[i].getNewX() + ship[i].getRealWidth() &&
							y >= ship[i].getNewY() && y <= ship[i].getNewY() + ship[i].getRealHeight()){
						if (ship[i].getX() != ship[i].getNewX() && ship[i].getX() != ship[i].getNewX() &&
								ship[i].getY() != ship[i].getNewY() && ship[i].getY() != ship[i].getNewY())
							shipMOVE = ship[i].getID();
						for (int i = ship[shipMOVE].getHeadColumn(); i <= ship[shipMOVE].getBodyColumn(); i++)
							for (int j = ship[shipMOVE].getHeadRow(); j <= ship[shipMOVE].getBodyRow(); j++){
								if (ship[shipMOVE].getRotation())
									player.setShipCell(j, i, 0);
								else
									player.setShipCell(j, i, 0);
								ship[shipMOVE].setReady(false);
								if (player.getShipCell(i, j) == 0){
									if (ship[shipMOVE].getRotation()){
										ship[shipMOVE].setRotation(false);
										transWidthHeight();
										if (ship[shipMOVE].getNewX() < 123 || ship[shipMOVE].getNewX() + ship[shipMOVE].getRealWidth() > 701 ||
												ship[shipMOVE].getNewY() < 167 || ship[shipMOVE].getNewY() + ship[shipMOVE].getRealHeight() > 745){
											ship[shipMOVE].setRotation(true);
											transWidthHeight();
										}
									}
									else{
										ship[shipMOVE].setRotation(true);
										transWidthHeight();
										if (ship[shipMOVE].getNewX() < 123 || ship[shipMOVE].getNewX() + ship[shipMOVE].getRealWidth() > 701 ||
												ship[shipMOVE].getNewY() < 167 || ship[shipMOVE].getNewY() + ship[shipMOVE].getRealHeight() > 745){
											ship[shipMOVE].setRotation(false);
											transWidthHeight();
										}
									}
									if (ship[shipMOVE].getRotation())
										player.setShipCell(j, i, ship[shipMOVE].getLengthWidth());
									else
										player.setShipCell(j, i, ship[shipMOVE].getLengthHeight());
									ship[shipMOVE].setReady(true);
								}
							}
						ship[shipMOVE].setField((int)((ship[shipMOVE].getNewY() - 167) / 72.25), (int)((ship[shipMOVE].getNewX() - 123) / 72.25),
																					 ship[shipMOVE].getHeadRow() + ship[shipMOVE].getLengthHeight() - 1,
																					 ship[shipMOVE].getHeadColumn() + ship[shipMOVE].getLengthWidth() - 1);
						shipXY(123, 167, 578, 578);
						shipMOVE = -1;
						break;
					}
				}
			}
			break;
	}
	glutPostRedisplay();
}

void MouseMove(int x, int y){
	move_mouseX = x;
	move_mouseY = y;
	if (frame == SHIP_POSITION_FRAME){
		if (shipMOVE != -1 && mouse_down == 0){
			ship[shipMOVE].setNewCoordinate(ship[shipMOVE].getOldX() - button_mouseX + move_mouseX,
																			ship[shipMOVE].getOldY() - button_mouseY + move_mouseY);
			ship[shipMOVE].setField((int)((ship[shipMOVE].getNewY() - 167) / 72.25), (int)((ship[shipMOVE].getNewX() - 123) / 72.25),
																	 ship[shipMOVE].getHeadRow() + ship[shipMOVE].getLengthHeight() - 1,
																	 ship[shipMOVE].getHeadColumn() + ship[shipMOVE].getLengthWidth() - 1);
		}
	}
	glutPostRedisplay();
}

void MousePassiveMotion(int x, int y){
	mouseX = x;
	mouseY = y;
	if (frame == SHIP_POSITION_FRAME){
		ship[shipMOVE].setOldCoordinate(ship[shipMOVE].getNewX(), ship[shipMOVE].getNewY());
		shipMOVE = -1;
	}
	glutPostRedisplay();
}

void glint_START_Timer(int id){
	if (glint_START)
		glint_START = false;
	else
		glint_START = true;

	if (frame == MAIN_FRAME)
		glutTimerFunc(200, glint_START_Timer, id);
}

void transWidthHeight(){
	GLfloat tempf;
	tempf = ship[shipMOVE].getRealWidth();
	ship[shipMOVE].setRealWidth(ship[shipMOVE].getRealHeight());
	ship[shipMOVE].setRealHeight(tempf);
	int tempi;
	tempi = ship[shipMOVE].getLengthWidth();
	ship[shipMOVE].setLengthWidth(ship[shipMOVE].getLengthHeight());
	ship[shipMOVE].setLengthHeight(tempi);
}

void initShipXY(){
	ship[shipMOVE].setOldCoordinate(ship[shipMOVE].getX(), ship[shipMOVE].getY());
	ship[shipMOVE].setNewCoordinate(ship[shipMOVE].getX(), ship[shipMOVE].getY());
	if (ship[shipMOVE].getRotation()){
		transWidthHeight();
		ship[shipMOVE].setRotation(false);
	}
	ship[shipMOVE].setReady(false);
	shipMOVE = -1;
}

