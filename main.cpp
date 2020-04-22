#include "main.h"

int main() {
	srand(time(NULL));
	
	background.load();
	title.load();
	reel.load();
	sea.load();
	radarBoard.load();
	ship0.load();
	ship1.load();
	ship2.load();
	ship3.load();
	ship4.load();
	ship5.load();
	back.load();
	wave.load();
	fire.load();

	computer.randomShips();
	
	shipInit();

	back.toBGR();

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(windowX, windowY);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Battle Ship");

	glutReshapeFunc(WindowSize);
	glutDisplayFunc(Display);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMove);
	glutPassiveMotionFunc(MousePassiveMotion);
	glutTimerFunc(200, glint_START_Timer, 1);

	glutMainLoop();
}

void shipInit(){
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

void WindowSize(int w, int h){
	sizeMagn *= h / windowY;
	windowX = w;
	windowY = h;
	glViewport(0, 0, w, h);
}

void MouseButton(int button, int state, int x, int y){
	mouse_down = state;
	button_mouseX = x;
	button_mouseY = y;
	switch (button){
	case GLUT_LEFT_BUTTON:
		switch (frame){
			case 0:
				if (x >= 923 && x <= 993 && y >= 643 && y <= 723){
					glutTimerFunc(200, glint_START_Timer, 1);
					frame++;
				}
				break;
			case 1:
				if (x >= 637.6 && x <= 807.6 && y >= 674 && y <= 729)
					frame++;
				else if (x >= 643 && x <= 802 && y >= 729 && y <= 784)
					frame--;
				break;
			case 2:
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
					frame--;
				}
				else if (x >= 1165 && x <= 1315 && y >= 620 && y <= 770){
					int i;
					for (i = 0; i < 6; i++){
						if (ship[i].getReady() == false)
							break;
					}
					if (i == 6){
						frame++;
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
			case 3:
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
			if (frame == 2){
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
	if (frame == 2){
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
	if (frame == 2){
		ship[shipMOVE].setOldCoordinate(ship[shipMOVE].getNewX(), ship[shipMOVE].getNewY());
		shipMOVE = -1;
	}
	glutPostRedisplay();
}

void Display(){
	glLoadIdentity();
	gluOrtho2D(0, windowX, windowY, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch (frame){
	case 0:
	case 1:
		Init_one();
		break;
	case 2:
		Init_two();
		break;
	case 3:
		Init_three();
		break;
	}
}

void Init_one(){
	background.show();
	setImageSize(0, 0, windowX, windowY);
	title.toTransparent(0, 0, 0, alpha);
	setImageSize(windowX / 2 - 360, 20, 508 * 1.5, 105 * 1.5);
	if (alpha < 255)
		alpha++;
	glDisable(GL_TEXTURE_2D);

	if (glint_START){
		glColor3f(1, 1, 0);
		setFontHeight(55);
		setFontXY(windowX / 2 - 80, windowY - 190);
		Print_Font("START");
		setFontXY(windowX / 2 - 74, windowY - 135);
		Print_Font("MENU");
	}

	if (frame == 0){
		reel.toTransparent();
		setImageSize(420, 20, 644, 824.6);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glColor3f(0, 0, 0);
		setFontHeight(45);
		setFontXY(650, 190);
		Print_Font("Battle Ship");
		setFontHeight(25);
		setFontXY(480, 190);
		pFile = fopen("rule.txt", "r");
		if (NULL == pFile){
			Print_Font("Open failure");
		}
		else{
			fread(buffer, 1024, 1, pFile);
			Print_Font("%s", buffer);
		}

		glColor3f(1, 0, 0);
		setFontHeight(100);
		setFontXY(925, 635);
		Print_Font("X");
	}

	glutPostRedisplay();
	glutSwapBuffers();
}

void Init_two(){
	radarBoard.show();
	setImageSize(0, 0, windowX, windowY);
	back.toTransparent();
	setImageSize(0, 0, 100, 100);
	glDisable(GL_TEXTURE_2D);

	battle_ship_green;
	checkerboard(123, 167, 578, 578, table, table, 2);

	for (int i = 5; i >= 0; i--){
		toTransparentImage(ship[i].getImage());
		setImageSize(ship[i].getX(), ship[i].getY(), ship[i].getWidth(), ship[i].getHeight(), 0, 0, 0);
		if (ship[i].getRotation())
			Counterclockwise_Degree_Rotation(ship[i].getNewX(), ship[i].getNewY());

		setImageSize(ship[i].getNewX(), ship[i].getNewY(), ship[i].getWidth(), ship[i].getHeight(), 0, 1, 0);
		glLoadIdentity();
		gluOrtho2D(0, windowX, windowY, 0);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	setFontHeight(50);
	setFontXY(0, 0);

	if (mouse_down){
		player.initShips();
		for (int i = 0; i < 6; i++)
			if (123 > ship[i].getNewX() || 701 < ship[i].getNewX() || 167 > ship[i].getNewY() || 745 < ship[i].getNewY()){
				ship[i].setReady(false);
			}
			else{
				for (int j = ship[i].getHeadColumn(); j <= ship[i].getBodyColumn(); j++)
					for (int k = ship[i].getHeadRow(); k <= ship[i].getBodyRow(); k++){
						if (ship[i].getRotation())
							player.setShipCell(k, j, ship[i].getLengthWidth());
						else
							player.setShipCell(k, j, ship[i].getLengthHeight());
						ship[i].setReady(true);
					}
			}
	}

	player.testShipTable(0, 200);
	computer.testShipTable(200, 200);

	glutSwapBuffers();
}

void Init_three(){
	sea.show();
	setImageSize(0, 0, windowX, windowY);

	battle_ship_blue;
	setFontHeight(67);
	setFontXY(85, 314);
	for (int i = 65; i < 65 + table; i++)
		Print_Font("%c\n", i);
	setFontXY(745, 314);
	for (int i = 65; i < 65 + table; i++)
		Print_Font("%c\n", i);
	setFontXY(140, 247);
	for (int i = 1; i < 1 + table; i++)
		Print_Font("% d ", i);
	setFontXY(800, 247);
	for (int i = 1; i < 1 + table; i++)
		Print_Font("% d ", i);

	battle_ship_blue;
	checkerboard(140, 310, 540, 540, table, table, 5);
	checkerboard(800, 310, 540, 540, table, table, 5);

	for (int i = 5; i >= 0; i--){
		shipMOVE = i;
		shipXY(140, 310, 540, 540);
		toTransparentImage(ship[i].getImage());
		if (ship[shipMOVE].getRealWidth() > ship[shipMOVE].getRealHeight() || ship[i].getRotation())
			Counterclockwise_Degree_Rotation(ship[i].getNewX(), ship[i].getNewY());
		setImageSize(ship[i].getNewX(), ship[i].getNewY(), ship[i].getWidth(), ship[i].getHeight(), 1, 1, 1);
		glLoadIdentity();
		gluOrtho2D(0, windowX, windowY, 0);
	}

	if (player_computer_flag && player_computer_sleep == false)
		glutTimerFunc(1, player_computer_sleep_Timer, 2);

	if (player_computer_flag && player_computer_sleep && palyer_down && palyer_init){
		computer.checkShots();
		glutTimerFunc(500, player_computer_flag_Timer, 3);
		palyer_down = false;
		palyer_init = false;
	}
	else if (player_computer_flag == false && player_computer_sleep){
		player.checkShots();
		palyer_down = true;
		palyer_init = true;
	}

	player.showBoard(140, 310, fire.getImage(), wave.getImage());
	computer.showBoard(800, 310, fire.getImage(), wave.getImage());

	Sleep(100);

	glColor3f(0, 0, 0);
	setFontHeight(55);
	setFontXY(windowX / 2 - 260, windowY / 2);

	if (computer.getHitCell(0) == 14 || computer.getHitCell(1) == 40 || player.getHitCell(0) == 14 || player.getHitCell(1) == 40){
		if (computer.getHitCell(0) == 14)
			Print_Font("You win the game");
		else if (computer.getHitCell(1) == 40)
			Print_Font("You are garbage");
		if (player.getHitCell(0) == 14)
			Print_Font("You lose the game");
		else if (player.getHitCell(1) == 40)
			Print_Font("You are garbage");
		palyer_down = false;
	}

	glutPostRedisplay();
	glutSwapBuffers();
}

void glint_START_Timer(int id){
	if (glint_START)
		glint_START = false;
	else
		glint_START = true;

	if (frame == 1)
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

void shipXY(GLfloat x, GLfloat y, GLfloat width, GLfloat height){
	ship[shipMOVE].setNewCoordinate(x + ship[shipMOVE].getHeadColumn() * width / 8 + (ship[shipMOVE].getLengthWidth() * width / 8 - ship[shipMOVE].getRealWidth()) / 2,
																	y + ship[shipMOVE].getHeadRow() * height / 8 + (ship[shipMOVE].getLengthHeight() * height / 8 - ship[shipMOVE].getRealHeight()) / 2);
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

void player_computer_sleep_Timer(int id){
	if (player_computer_sleep)
		player_computer_sleep = false;
	else
		player_computer_sleep = true;
}

void player_computer_flag_Timer(int id){
	if (player_computer_flag){
		player_computer_flag = false;
		do{
			player.setRow(rand() % 8);
			player.setColumn(rand() % 8);
		} while (player.getBoardCell() != -1);
	}
	else if (player_computer_sleep == false)
		player_computer_flag = true;
}
