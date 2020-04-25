#include "draw.h"

void line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat LineWidth){
	glLineWidth(LineWidth);
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void Hollow_Square(GLfloat x1, GLfloat y1, GLfloat width, GLfloat height, GLfloat LineWidth){
	GLfloat x2 = x1 + width;
	GLfloat y2 = y1 + height;
	glLineWidth(LineWidth);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x1, y2);
	glVertex2f(x2, y2);
	glVertex2f(x2, y1);
	glEnd();
}

void Solid_Square(GLfloat x1, GLfloat y1, GLfloat width, GLfloat height){
	GLfloat x2 = x1 + width;
	GLfloat y2 = y1 + height;
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x1, y2);
	glVertex2f(x2, y2);
	glVertex2f(x2, y1);
	glEnd();
}

void checkerboard(GLfloat x, GLfloat y, GLfloat width, GLfloat height, int width_cell, int height_cell, GLfloat LineWidth){
	for (int i = 0; i <= width_cell; i++){
		if (i == 0 || i == width_cell)
			line(x + width / width_cell * i, y, x + width / width_cell * i, y + height, LineWidth);
		else
			line(x + width / width_cell * i, y, x + width / width_cell * i, y + height, LineWidth / 2);
	}
	for (int j = 0; j <= height_cell; j++){
		if (j == 0 || j == height_cell)
			line(x, y + height / height_cell * j, x + width, y + height / height_cell * j, LineWidth);
		else
			line(x, y + height / height_cell * j, x + width, y + height / height_cell * j, LineWidth / 2);
	}
}

void counterclockwiseDegreeRotation(GLfloat x, GLfloat y){
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-x, -y, 0);
	glTranslatef(y, x, 0);
}
