#include "raylib.h"
#include "GWindow.h"
#include "GLabel.h"

int main()
{
	const int windowWidth = 540;
	const int windowHeight = 600;
	const Color BGCOLOR = {70, 119, 202, 255};
	const int TEXTSIZE = 20;
	const int MESSAGE_LENGTH = 11;

	const char windowTitle[MESSAGE_LENGTH] = "Shapes GUI";
	const char message[MESSAGE_LENGTH] = "I'm OOPed!";
	GWindow mainWindow(windowWidth, windowHeight, BGCOLOR, windowTitle);
	GLabel mainMessage((windowWidth / 2) - (MeasureText(message, TEXTSIZE) / 2), 
					   windowWidth / 4, 
					   "I'm OOPed!", 
					   MESSAGE_LENGTH, 
					   TEXTSIZE, 
					   WHITE);

	SetTargetFPS(30);
	
	while(!WindowShouldClose())
	{
		// Draw
		BeginDrawing();
			mainWindow.draw();
			mainMessage.draw();
		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}