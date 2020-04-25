#ifndef MOUSE_H
#define MOUSE_H
class Mouse{	
	struct Coordinate{
		int x;
		int y;
	};

	public:
		Mouse() = default;
		
		void setMouseMotionCoordinate(int, int);
		int getMouseMotionX();
		int getMouseMotionY();
		
		void setMouseMoveCoordinate(int, int);
		int getMouseMoveX();
		int getMouseMoveY();
		
		void setMouseClickCoordinate(int, int);
		int getMouseClickX();
		int getMouseClickY();
		bool isMouseClickRangeCoordinate(int, int, int, int);
		
		void setMouseClicked(int);
		int getMouseClicked();
		
		void setMouseButton(int);
		int getMouseButton();
		
	private:
		Coordinate motion = {0};
		Coordinate move = {0};
		Coordinate click = {0};
		int clicked = 0;
		int button = 0;
};

#endif
