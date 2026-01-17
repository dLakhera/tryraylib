#include <raylib.h>
#include <iostream>

#include "headers/Drawer.h"

#define WIDTH 1000
#define HEIGHT 1000


int main(){

	InitWindow(WIDTH, HEIGHT, "My RayLib App!");

	Drawer drw = Drawer();

	SetTargetFPS(60);
	// WaitTime(2);
	while(!WindowShouldClose()){
		
		BeginDrawing();

		ClearBackground(WHITE);
	
		drw.update();
		drw.draw();
	
		EndDrawing();

	}

	CloseWindow();

	std::cout << "Deepak Lakhera|!" << std::endl;
	return 0;
}

