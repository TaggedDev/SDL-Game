#pragma once
class Block
{
public:
	int getX();
	int getY();
	Block(int x, int y) {
		x1 = x;
		y1 = y;
		x2 = x + 60;
		y2 = y + 60;
	};
	bool ColliderEnterBlock(int x, int y);
private:
	int x1, x2, y1, y2;
};
