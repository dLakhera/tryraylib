#pragma once

#include "TextInput.h"
#include <iostream>
#include <raylib.h>
#include <cmath>
#include <raymath.h>
#include <utility>

#define RAY_COUNT 1200
#define RAY_LENGTH 100000

struct obj{
	int x;
	int y;
	int r;
};

class Drawer{
	

	private:
		TxtI::TextInput input1 = TxtI::TextInput();
		int center_x, center_y, radius;
		Vector2 DistancePointToLine2D(Vector2 point, Vector2 lineStart, Vector2 lineEnd);
		
		std::pair<Vector2, Vector2> rays[RAY_COUNT];
		struct obj Obj;

	public:
		Drawer(int x = 450,int y = 450 ,int r = 50);
		void draw();
		void update();
};

