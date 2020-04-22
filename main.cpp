#include "mainWindow.h"

int main() {
	srand(time(NULL));
	
	computer.randomShips();
	
	shipInit();

	windowSet();
	windowEvent();
}
