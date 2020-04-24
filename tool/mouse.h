#ifndef MOUSE_H
#define MOUSE_H
class Mouse{	
	struct Coordinate{
		int x;
		int y;
	};

	public:
		Mouse() = default;
		void setMotionCoordinate(int, int);
		int getMotionX();
		int getMotionY();
		void setClickCoordinate(int, int);
		int getClickX();
		int getClickY();
		void setMoveCoordinate(int, int);
		int getMoveX();
		int getMoveY();
		void setClicked(int);
		int getClicked();
	private:
		Coordinate motion = {0};
		Coordinate click = {0};
		Coordinate move = {0};
		int clicked = 0;
};

#endif
