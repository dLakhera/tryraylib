#include "headers/Drawer.h"

float distance(Vector2 pt1, Vector2 pt2){

	return pow(pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2),0.5); 
}

Vector2 Drawer::DistancePointToLine2D(Vector2 point, Vector2 lineStart, Vector2 lineEnd) {
    Vector2 lVec = Vector2Subtract(lineEnd, lineStart);
    Vector2 pVec = Vector2Subtract(point, lineStart);

	float t = Vector2DotProduct(pVec, lVec) / Vector2LengthSqr(lVec);

	if (t < 0.0f) t = 0.0f;
	if (t > 1.0f) t = 1.0f;
    Vector2 closestPoint = Vector2Add(lineStart, Vector2Scale(lVec, t));
	return closestPoint;
}

Drawer::Drawer(int center_x, int center_y, int radius)
        : center_x(center_x),
          center_y(center_y),
          radius(radius) {

	std::cout << "Here at initiation!" << std::endl;

	DrawCircle(this->center_x, this->center_y, this->radius, RED);
	
	Obj = {700, 650, 150};

	// std::cout << this->Obj.x << this->Obj.y << this->Obj.r << std::endl;
	
};

void Drawer::update(){	

	this->input1.update();

	if (this->input1.isUpdated){
		this->center_x = this->input1.getX();
		this->center_y = this->input1.getY();
		this->radius =  this->input1.getRadius();
		
		this->input1.isUpdated = false;
	}	

	Vector2 mousePos = GetMousePosition();
	Vector2 center = {center_x, center_y};
	Vector2 delta = GetMouseDelta();
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) and (this->radius < distance(center, mousePos))){
		
		center_x += delta.x;
		center_y += delta.y;
	}

	int ctr = 0;

	for(int i = 0; i < RAY_COUNT; i++) {

		float angle = (float)((float)i/RAY_COUNT) * 360 * DEG2RAD;
		Vector2 direction = {cosf(angle), sinf(angle)};
		Vector2 rayEnd = {center_x + direction.x*RAY_LENGTH, center_y + direction.y*RAY_LENGTH};
	
		Vector2 objCenter = {Obj.x, Obj.y};
		Vector2 light = {center_x, center_y};

		// light souce inside the circle object
		if (distance(objCenter, light) < Obj.r){
			rays[i] = std::make_pair(light, light);
			continue;
		}

		Vector2 ray = Vector2Subtract(rayEnd, light);	
		Vector2 rayDir = Vector2Normalize(ray); 

		Vector2 L = Vector2Subtract(objCenter, light);

		float tca = Vector2DotProduct(L, rayDir);
		
		// Greater than 90 deg angle between ray and (lightsource, objcenter) vector, meaning it is going away from the object from the start 
		if (tca < 0.0f) {
			rays[i] = std::make_pair(rayEnd, rayEnd);
			continue;
		}

		float closestDistance = Vector2DotProduct(L,L) - tca*tca;

		// float lToRayEnd = Vector2Length(Vector2Subtract(light, rayEnd));
		// float lToPerp = Vector2Length(Vector2Subtract(light, Vector2Scale(rayDir, tca)));

		if (closestDistance < Obj.r*Obj.r) { // && lToRayEnd >= lToPerp) {
			
			float toMove = sqrtf(Obj.r*Obj.r - closestDistance);
			float firstIntersection = tca - toMove;
			float secondIntersection = tca + toMove;

			Vector2 firstRayIntersect = Vector2Add(light, Vector2Scale(rayDir, firstIntersection));
			Vector2 secRayIntersect = Vector2Add(light, Vector2Scale(rayDir, secondIntersection)); 
			// if (distance(light, rayEnd) > distance(light, secRayIntersect)){
			// 	rays[i] = std::make_pair(firstRayIntersect, secRayIntersect);
			// } else {
			// 	rays[i] = std::make_pair(firstRayIntersect, firstRayIntersect);
			// }
			
			rays[i] = std::make_pair(firstRayIntersect, secRayIntersect);

			// rayEnd = firstRayIntersect;	
			ctr++;
		}
		else	
			rays[i] = std::make_pair(rayEnd, rayEnd);

	}

};

void Drawer::draw(){

	DrawText("Enter the radius of the circle ball:", 50, 50, 20, BLACK);	
	DrawCircle(this->center_x, this->center_y, this->radius, RED);
	// std::cout<<Obj.x << " " << Obj.y << " " << Obj.r << std::endl;
	DrawCircle(Obj.x, Obj.y, Obj.r,DARKBLUE);

	Vector2 objCenter = {Obj.x, Obj.y};
	Vector2 light = {center_x, center_y};

	Vector2 L = Vector2Subtract(objCenter, light);

	for(int i=0;i<RAY_COUNT;i++) {
		// DrawLineV(light, rays[i].first, YELLOW);
		if (rays[i].first == rays[i].second){
			DrawLineV(light, rays[i].first, YELLOW);
		} else{

			DrawLineV(light, rays[i].first, YELLOW);
			Vector2 rayDir = {cosf((float)i/RAY_COUNT*360*DEG2RAD), sinf((float)i/RAY_COUNT*360*DEG2RAD)};	
			float len = Vector2Length(Vector2Subtract(Vector2Scale(rayDir, RAY_LENGTH), rays[i].second));
			DrawLineV(rays[i].second, Vector2Add(rays[i].second, Vector2Scale(rayDir, len)), BLACK);

		}

	}

	this->input1.draw();

};
