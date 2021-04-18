#pragma once
#include <SDL.h>
class KeyboardHandler 
{
public:
	bool isReleased(int i, int mass);
	int mass[10];
private:
};
