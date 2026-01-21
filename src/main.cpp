#include <raylib.h>
#include <iostream>

#include "headers/Drawer.h"

#define WIDTH 1000
#define HEIGHT 1000
#define PI 3.141592653589793


int main(){

	const int currentMonitor = GetCurrentMonitor(); // Get the index of the current display
	const int screenWidth = GetMonitorWidth(currentMonitor);
	const int screenHeight = GetMonitorHeight(currentMonitor);

	std::cout << screenWidth << " " << screenHeight << std::endl;

	// InitWindow(screenWidth, screenHeight, "My RayLib App!");
	InitWindow(WIDTH, HEIGHT, "My RayLib App!");

	Drawer drw = Drawer(WIDTH/2, HEIGHT/2, 25);

	SetTargetFPS(120);
	// WaitTime(2);
	while(!WindowShouldClose()){
		
		BeginDrawing();

		ClearBackground(MAROON);

		drw.update();
		drw.draw();
	
		EndDrawing();

	}

	CloseWindow();

	std::cout << "Deepak Lakhera|!" << std::endl;
	return 0;
}

