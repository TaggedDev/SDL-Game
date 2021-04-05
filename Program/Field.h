#pragma once
#include "Tank.h"
#include <vector>
using namespace std;
class Field
{
public:
	void Render();
private:
	vector<Tank> enemies;
};

