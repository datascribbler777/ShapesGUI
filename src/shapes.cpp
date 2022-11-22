#include "raylib.h"

int main()
{
	const int windowWidth = 540;
	const int windowHeight = 600;
	const Color BGCOLOR = {70, 119, 202, 255};
	const int TEXTSIZE = 20;
	const int MESSAGE_SIZE = 11;
	// C style string because C is for Cancer
	char message[MESSAGE_SIZE] = "I'm alive!";
	
	InitWindow(windowWidth, windowHeight, "Shapes GUI");
	SetTargetFPS(30);
	
	while(!WindowShouldClose())
	{
		// Draw
		BeginDrawing();
			// Fill background with color
			ClearBackground(BGCOLOR);
			
			// Draw some text!
			DrawText(message, 
					(windowWidth / 2) - (MeasureText(message, TEXTSIZE) / 2), 
					 windowHeight / 4, 
					 TEXTSIZE, 
					 WHITE);
		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}