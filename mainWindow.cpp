#include "mainWindow.h"

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
