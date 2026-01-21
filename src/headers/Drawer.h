#pragma once

#include "TextInput.h"
#include <iostream>
#include <raylib.h>
#include <cmath>
#include <raymath.h>

#define RAY_COUNT 1000
#define RAY_LENGTH 1000

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
		
		Vector2 rays[RAY_COUNT];
		struct obj Obj;

	public:
		Drawer(int x = 450,int y = 450 ,int r = 50);
		void draw();
		void update();
};

