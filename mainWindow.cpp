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
	drawTest();
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
			mainFrame::display();
			break;
		case SHIP_POSITION_FRAME:
			shipPositionFrame::display();
			break;
		case BATTLE_FRAME:
			battleFrame::display();
			break;
	}
}

void drawTest(){
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glColor3f(1, 1, 0);
	setFontHeight(30);
	setFontXY(0, 0);
	printFont(" state: %d\n clickX: %d\n clickY: %d\n moveX: %d\n moveY: %d\n motionX: %d\n motionY: %d",
						mouse.getMouseState(), mouse.getMouseClickX(), mouse.getMouseClickY(),
						mouse.getMouseMoveX(), mouse.getMouseMoveY(),
						mouse.getMouseMotionX(), mouse.getMouseMotionY());

//	player.testBoardTable(300, 0);
//	computer.testBoardTable(500, 0);
	player.testShipTable(700, 0);
	computer.testShipTable(900, 0);
//	player.testHitTable(1050, 0);
//	computer.testHitTable(1100, 0);

//	glColor3f(1, 1, 0);
//	setFontHeight(20);
//	setFontXY(1150, 0);
//	printFont("ship rotation:\n");
//	for (int i = 0; i < 6; i++){
//		printFont("%d: %d\n", ship[i].getID(), ship[i].getShipRotation());
//	}
//	
//	glColor3f(1, 1, 0);
//	setFontHeight(20);
//	setFontXY(1300, 0);
//	printFont("ship ready:\n");
//	for (int i = 0; i < 6; i++){
//		printFont("%d: %d\n", ship[i].getID(), ship[i].getShipReady());
//	}
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
	mouse.setMouseState(state);
	mouse.setMouseClickCoordinate(x, y);
}

void catchMouseButton(int button, int state, int x, int y){
	mouse.setMouseButton(button);
	switch (button){
		case GLUT_LEFT_BUTTON:
			switchFrameClick(state, x, y);
			break;
		case GLUT_RIGHT_BUTTON:
			if (frame == SHIP_POSITION_FRAME){
				shipPositionFrame::rightClick(state, x, y);
			}
			break;
	}
}

void switchFrameClick(int state, int x, int y){
	switch (frame){
		case MAIN_FRAME:
			mainFrame::click(x, y);
			break;
		case SHIP_POSITION_FRAME:
			shipPositionFrame::click(state, x, y);
			break;
		case BATTLE_FRAME:
			battleFrameClick::battleFrameClick(state, x, y);
			break;
	}
}

void catchMouseMove(int x, int y){
	setMouseMoveCoordinates(x, y);
	shipPositionFrame::move(x, y);
	glutPostRedisplay();
}

void setMouseMoveCoordinates(int x, int y){
	mouse.setMouseMoveCoordinate(x, y);
}
void catchMousePassiveMotion(int x, int y){
	setMouseMotionCoordinates(x, y);
	shipPositionFrame::motion();
	glutPostRedisplay();
}

void setMouseMotionCoordinates(int x, int y){
	mouse.setMouseMotionCoordinate(x, y);
}
