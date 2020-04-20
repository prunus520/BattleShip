//			main.cpp

#include "battle_ship_function.h"
#include "battleship.h"
#include "ship.h"

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
void check_shot(int row, int column, int shot[][table], int ships[][table], int board[][table], int hits[]);
void transWidthHeight();
void shipXY(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
void initShipXY();
void player_computer_sleep_Timer(int id);
void player_computer_flag_Timer(int id);

float windowX = 1196 * 1.2, windowY = 720 * 1.2;
float sizeMagn = 1;
bool glint_START = true;
int frame = 1;
int mouseX, mouseY;
int button_mouseX, button_mouseY;
int move_mouseX, move_mouseY;
int pointX = windowX, pointY = 0;
IplImage *battle_ship = cvLoadImage("img//battle_ship.jpg");
IplImage *battleship = cvLoadImage("img//battleship.png");
IplImage *reel = cvLoadImage("img//reel.png");
IplImage *sea = cvLoadImage("img//sea.jpg");
IplImage *radar_board = cvLoadImage("img//radar_board.jpg");
IplImage *ship0 = cvLoadImage("img//ship0.png");
IplImage *ship1 = cvLoadImage("img//ship1.png");
IplImage *ship2 = cvLoadImage("img//ship2.png");
IplImage *ship3 = cvLoadImage("img//ship3.png");
IplImage *ship4 = cvLoadImage("img//ship4.png");
IplImage *ship5 = cvLoadImage("img//ship5.png");
IplImage *back = cvLoadImage("img//back.png");
IplImage *wave = cvLoadImage("img//wave.jpg");
IplImage *fire = cvLoadImage("img//fire.png");
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

int main() {
	srand(time(NULL));
	
	computer.randomShips();
	
	shipInit();

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(windowX, windowY);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Battle Ship");

	cvCvtColor(battle_ship, battle_ship, CV_BGR2RGB);
	cvCvtColor(battleship, battleship, CV_BGR2RGB);
	cvCvtColor(reel, reel, CV_BGR2RGB);
	cvCvtColor(sea, sea, CV_BGR2RGB);
	cvCvtColor(ship0, ship0, CV_BGR2RGB);
	cvCvtColor(ship1, ship1, CV_BGR2RGB);
	cvCvtColor(ship2, ship2, CV_BGR2RGB);
	cvCvtColor(ship3, ship3, CV_BGR2RGB);
	cvCvtColor(ship4, ship4, CV_BGR2RGB);
	cvCvtColor(ship5, ship5, CV_BGR2RGB);
	cvCvtColor(wave, wave, CV_BGR2RGB);
	cvCvtColor(fire, fire, CV_BGR2RGB);
	//	cvCvtColor( back, back, CV_BGR2RGB );

	glutReshapeFunc(WindowSize);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(KeyboardSpecial);
	glutDisplayFunc(Display);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMove);
	glutPassiveMotionFunc(MousePassiveMotion);
	glutTimerFunc(200, glint_START_Timer, 1);

	glutMainLoop();

	cvReleaseImage(&battle_ship);
	cvReleaseImage(&battleship);
	cvReleaseImage(&reel);
	cvReleaseImage(&sea);
	cvReleaseImage(&radar_board);
	cvReleaseImage(&ship0);
	cvReleaseImage(&ship1);
	cvReleaseImage(&ship2);
	cvReleaseImage(&ship3);
	cvReleaseImage(&ship4);
	cvReleaseImage(&ship5);
	cvReleaseImage(&wave);
	cvReleaseImage(&back);
}

void shipInit(){
	ship[0].setImage(ship0);
	ship[0].setCoordinate(1108, 186);
	ship[0].setSize(16, 67.2);
	ship[0].setLength(1, 1);

	ship[1].setImage(ship1);
	ship[1].setCoordinate(1161, 186);
	ship[1].setSize(24, 65.6);
	ship[1].setLength(1, 1);
	
	ship[2].setImage(ship2);
	ship[2].setCoordinate(1228, 186);
	ship[2].setSize(16, 67.2);
	ship[2].setLength(1, 1);
	
	ship[3].setImage(ship3);
	ship[3].setCoordinate(1100, 280);
	ship[3].setSize(65, 212.5);
	ship[3].setLength(1, 3);
	
	ship[4].setImage(ship4);
	ship[4].setCoordinate(1202, 280);
	ship[4].setSize(50, 212.5);
	ship[4].setLength(1, 3);
	
	ship[5].setImage(ship5);
	ship[5].setCoordinate(1010, 170);
	ship[5].setSize(54, 336);
	ship[5].setLength(1, 5);
}

void WindowSize(int w, int h){
	sizeMagn *= h / windowY;
	windowX = w;
	windowY = h;
	glViewport(0, 0, w, h);
}

void Keyboard(unsigned char key, int x, int y){
	if (key == ESC)
		exit(1);
}

void KeyboardSpecial(int key, int x, int y){
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
	glLoadIdentity();																		//��_��l���Шt ( ���߬� 0 , 0 )
	gluOrtho2D(0, windowX, windowY, 0);									//�]�w2D���Шt ( ���W�� 0 , 0 )
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�M���w�s

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
	Image(battle_ship);
	Image_Size(0, 0, windowX, windowY);
	Image_Transparent(battleship, 0, 0, 0, alpha);
	Image_Size(windowX / 2 - 360, 20, 508 * 1.5, 105 * 1.5);
	if (alpha < 255)
		alpha++;
	glDisable(GL_TEXTURE_2D);

	//�{�{�� START �r��
	if (glint_START){
		glColor3f(1, 1, 0);
		setFontHeight(55);
		setFontXY(windowX / 2 - 80, windowY - 190);
		Print_Font("START");
		setFontXY(windowX / 2 - 74, windowY - 135);
		Print_Font("MENU");
	}

	if (frame == 0){
		Image_Transparent(reel);
		Image_Size(420, 20, 644, 824.6);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); //�C��[�G
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

	glutPostRedisplay(); //���sø�s
	glutSwapBuffers();	 //�洫��ӽw�İϫ��w
}

void Init_two(){
	Image(radar_board);
	Image_Size(0, 0, windowX, windowY);
	Image_Transparent(back);
	Image_Size(0, 0, 100, 100);
	glDisable(GL_TEXTURE_2D);

	battle_ship_green;
	checkerboard(123, 167, 578, 578, table, table, 2);

	for (int i = 5; i >= 0; i--){
		Image_Transparent(ship[i].getImage());
		Image_Size(ship[i].getX(), ship[i].getY(), ship[i].getWidth(), ship[i].getHeight(), 0, 0, 0);
		if (ship[i].getRotation())
			Counterclockwise_Degree_Rotation(ship[i].getNewX(), ship[i].getNewY());

		Image_Size(ship[i].getNewX(), ship[i].getNewY(), ship[i].getWidth(), ship[i].getHeight(), 0, 1, 0);
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
	Image(sea);
	Image_Size(0, 0, windowX, windowY);

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
		Image_Transparent(ship[i].getImage());
		if (ship[shipMOVE].getRealWidth() > ship[shipMOVE].getRealHeight() || ship[i].getRotation())
			Counterclockwise_Degree_Rotation(ship[i].getNewX(), ship[i].getNewY());
		Image_Size(ship[i].getNewX(), ship[i].getNewY(), ship[i].getWidth(), ship[i].getHeight(), 1, 1, 1);
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

	player.showBoard(140, 310, fire, wave);
	computer.showBoard(800, 310, fire, wave);

	Sleep(100);

	glColor3f(0, 0, 0);
	setFontHeight(55);
	setFontXY(windowX / 2 - 260, windowY / 2);

	/*result( computer_hits );
	result( player_hits );*/
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
