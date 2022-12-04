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
	const int NUM_SIDES_LABEL_LENGTH = 37;
	const char windowTitle[MESSAGE_LENGTH] = "Shapes GUI";
	const char message[NUM_SIDES_LABEL_LENGTH] = "How many sides does your shape have?";

	GWindow mainWindow(windowWidth, windowHeight, BGCOLOR, windowTitle);
	GLabel numSidesLabel("numSidesLabel", 
					   (windowWidth / 2) - (MeasureText(message, TEXTSIZE) / 2), 
					   windowWidth / 4, 
					   message, 
					   NUM_SIDES_LABEL_LENGTH, 
					   TEXTSIZE, 
					   WHITE);
	
	mainWindow.addComponent(numSidesLabel);

	SetTargetFPS(30);
	
	while(!WindowShouldClose())
	{
		// Draw
		BeginDrawing();
			mainWindow.draw();
		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}