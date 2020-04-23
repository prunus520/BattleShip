#include "mainWindow.h"

int main() {
	srand(time(NULL));
	
	computer.randomShips();
	
	windowSet();
	windowEvent();
}
