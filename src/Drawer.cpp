#include "headers/Drawer.h"

Drawer::Drawer(int center_x, int center_y, int radius)
        : center_x(center_x),
          center_y(center_y),
          radius(radius) {
	
	DrawCircle(this->center_x, this->center_y, this->radius, RED);

};

void Drawer::update(){	

	this->input1.update();

	if (this->input1.isUpdated){
		this->center_x = this->input1.getX();
		this->center_y = this->input1.getY();
		this->radius =  this->input1.getRadius();
		
		this->input1.isUpdated = false;
	}	

};

void Drawer::draw(){

	DrawText("Enter the location(x,y) and the radius of the circle ball:", 50, 50, 20, BLACK);	
	DrawCircle(this->center_x, this->center_y, this->radius, RED);

	this->input1.draw();

};
