#include "headers/TextInput.h"

bool TxtI::TextInput::checkMouseOnText(Vector2 vec, Rectangle rec){

	return CheckCollisionPointRec(vec, rec);

}


int TxtI::TextInput::getX(){

	return this->x;

}

int TxtI::TextInput::getY(){

	return this->y;

}

int TxtI::TextInput::getRadius(){

	return this->r;

}

void TxtI::TextInput::update(){

	this->mouseOnText = checkMouseOnText(GetMousePosition(), this->textBox);
	if (this->mouseOnText)
        {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            int key = GetCharPressed();

            // Check if more characters have been pressed on the same frame
            if (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (this->letterCount < MAX_INPUT_CHARS))
                {
                    this->name[this->letterCount] = (char)key;
                    this->name[this->letterCount+1] = '\0'; // Add null terminator at the end of the string
                    this->letterCount++;
                }

                key = GetCharPressed();  // Check next character in the queue
				this->checkInp();
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                this->letterCount--;
                if (this->letterCount < 0) this->letterCount = 0;
                this->name[this->letterCount] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

	if (this->mouseOnText) this->frameCounter++;
	else this->frameCounter = 0;

}

void TxtI::TextInput::draw(){

	DrawRectangleRec(this->textBox, LIGHTGRAY);
	
	if (this->mouseOnText) DrawRectangleLines((int)this->textBox.x, (int)this->textBox.y, (int)this->textBox.width, (int)this->textBox.height, RED);
	else DrawRectangleLines((int)this->textBox.x, (int)this->textBox.y, (int)this->textBox.width, (int)this->textBox.height, DARKGRAY);

	DrawText(name, (int)this->textBox.x + 5, (int)this->textBox.y + 8, 40, MAROON);

	DrawText(TextFormat("INPUT CHARS: %i/%i", this->letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY);

	if (this->mouseOnText)
	{
		if (this->letterCount < MAX_INPUT_CHARS)
		{
			// Draw blinking underscore char
			if (((this->frameCounter/20)%2) == 0) DrawText("_", (int)this->textBox.x + 8 + MeasureText(name, 40), (int)this->textBox.y + 12, 40, MAROON);
		}
		else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
	}
}

void TxtI::TextInput::checkInp(){
	
	int commCounter=0,o = 0;
	int i = 0;
	for(i=0; this->name[i]!='\0';i++) commCounter+=(this->name[i] == ',');
	int arr[3] = {0};


	if (commCounter == 2 && this->name[i-1]!=','){
	
		char ch[4];
	

		for(int i =0, j=0,k=0; this->name[i]!='\0'; i++){
		
			if (this->name[i]!=','){
				ch[j++] = this->name[i];
				// ctr+=1;
			} else{
				ch[j] = '\0';
				j = 0;

				std::cout <<  std::stoi(ch) << std::endl;
				arr[k++] = std::stoi(ch);
			}
		}

		arr[2] = std::stoi(ch);

		for(int i=0;i<3;i++) std::cout << arr[i] << " ";
		std::cout << std::endl;

		this->x=arr[0], this->y=arr[1], this->r = arr[2];	
		this->isUpdated = true;

	} 

}

