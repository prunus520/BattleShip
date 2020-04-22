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
	glutMouseFunc(MouseClick);
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

void MouseClick(int button, int state, int x, int y){
	mouse_down = state;
	button_mouseX = x;
	button_mouseY = y;
	switch (button){
	case GLUT_LEFT_BUTTON:
		switch (frame){
			case MAIN_FRAME:
				mainFrameClick(x, y);
				break;
			case SHIP_POSITION_FRAME:
				shipPositionFrameClick(state, x, y);
				break;
			case BATTLE_FRAME:
				battleFrameClick(state, x, y);
				break;
			}
			break;
		case GLUT_RIGHT_BUTTON:
			shipPositionFrameRightClick(state, x, y);
			break;
	}
	glutPostRedisplay();
}

void MouseMove(int x, int y){
	move_mouseX = x;
	move_mouseY = y;
	shipPositionFrameMove(x, y);
	glutPostRedisplay();
}

void MousePassiveMotion(int x, int y){
	mouseX = x;
	mouseY = y;
	shipPositionFrameMotion(x, y);
	glutPostRedisplay();
}
