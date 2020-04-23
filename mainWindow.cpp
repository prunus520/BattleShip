#include "mainWindow.h"

void createGlutWindow(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(centerWindowX(), centerWindowY());
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Battle Ship");
}

int centerWindowX(){
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	return (screenWidth - windowWidth) / 2;
}

int centerWindowY(){
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	return (screenHeight - windowHeight) / 2;
}

void catchGlutEvent(){
	catchWindowSizeEvent();
	catchDisplayEvent();
	catchMouseEvent();
	catchTimerEvent();

	glutMainLoop();
}

void catchWindowSizeEvent(){
	glutReshapeFunc(catchWindowSize);
}

void catchWindowSize(int width, int height){
	setScale(width, height);
	changeWindowSize(width, height);
}

void setScale(int width, int height){
	scaleX *= width / windowWidth;
	scaleY *= height / windowHeight;
}

void changeWindowSize(int width, int height){
	windowWidth = width;
	windowHeight = height;
	glViewport(0, 0, windowWidth, windowHeight);
}

void catchDisplayEvent(){
	glutDisplayFunc(catchDisplay);
}

void catchDisplay(){
	resetCoordinates();
	clearCanvas();
	switchFrame();
	updateCanvas();
}

void resetCoordinates(){
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, windowHeight, 0);
}

void clearCanvas(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void switchFrame(){
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
}

void updateCanvas(){
	glutPostRedisplay();
	glutSwapBuffers();
}

void catchMouseEvent(){
	glutMouseFunc(catchMouseClick);
	glutMotionFunc(catchMouseMove);
	glutPassiveMotionFunc(catchMousePassiveMotion);
}

void catchMouseClick(int button, int state, int x, int y){
	setMouseClickCoordinates(state, x, y);
	catchMouseButton(button, state, x, y);
	glutPostRedisplay();
}

void setMouseClickCoordinates(int state, int x, int y){
	mouseDown = state;
	mouseClickX = x;
	mouseClickY = y;
}

void catchMouseButton(int button, int state, int x, int y){
	switch (button){
		case GLUT_LEFT_BUTTON:
			switchFrameClick(state, x, y);
			break;
		case GLUT_RIGHT_BUTTON:
			shipPositionFrameRightClick(state, x, y);
			break;
	}
}

void switchFrameClick(int state, int x, int y){
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
}

void catchMouseMove(int x, int y){
	setMouseMoveCoordinates(x, y);
	shipPositionFrameMove(x, y);
	glutPostRedisplay();
}

void setMouseMoveCoordinates(int x, int y){
	mouseMoveX = x;
	mouseMoveY = y;
}

void catchMousePassiveMotion(int x, int y){
	setMouseMotionCoordinates(x, y);
	shipPositionFrameMotion(x, y);
	glutPostRedisplay();
}

void setMouseMotionCoordinates(int x, int y){
	mouseX = x;
	mouseY = y;
}

void catchTimerEvent(){
	glutTimerFunc(200, glint_START_Timer, 1);
}
