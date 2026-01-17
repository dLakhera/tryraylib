#pragma once

#include "TextInput.h"
#include <iostream>
#include <raylib.h>

class Drawer{
	

	private:
		TxtI::TextInput input1 = TxtI::TextInput();
		int center_x, center_y, radius;

	public:
		Drawer(int x = 450,int y = 450 ,int r = 50);
		void draw();	
		void update();
};

