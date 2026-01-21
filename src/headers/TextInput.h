#pragma once

#include <raylib.h>
#include <string>
#include <iostream>

namespace TxtI{

#define MAX_INPUT_CHARS 4


class TextInput{
private:
	Rectangle textBox = { 150, 100, 700, 100 };	
	char name[MAX_INPUT_CHARS + 1] = {};
	bool mouseOnText = false;
	long long int frameCounter = 0;
	long long int letterCount= 0;

	int x=0,y=0,r = 0;

public:
	
	
	bool isUpdated = false;
	bool checkMouseOnText(Vector2 mousePosition, Rectangle rec);
	void update();
	void draw();
	
	int getX();
	int getY();
	int getRadius();

	void checkInp();

};
}

