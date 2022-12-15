#include "raylib.h"
#include "GWindow.h"
#include "GLabel.h"
#include "GTextBox.h"
#include "GTexture.h"
#include "GButton.h"
#include <string>

int main()
{
	const int WINDOW_WIDTH = 540;
	const int WINDOW_HEIGHT = 600;
	const Color BGCOLOR = {70, 119, 202, 255};
	const int TEXTSIZE = 20;
	const int MESSAGE_LENGTH = 11;
	const int NUM_SIDES_LABEL_LENGTH = 37;
	const char windowTitle[MESSAGE_LENGTH] = "Shapes GUI";
	const char message[NUM_SIDES_LABEL_LENGTH] = "How many sides does your shape have?";
	const int NUMSIDES_TEXTBOX_WIDTH = 225;
	const int TEXTBOX_HEIGHT = 30;
	const int GUI_SPACER = 30;

	GWindow mainWindow(WINDOW_WIDTH, WINDOW_HEIGHT, BGCOLOR, windowTitle);
	GLabel numSidesLabel("numSidesLabel", 
					   (WINDOW_WIDTH / 2) - (MeasureText(message, TEXTSIZE) / 2), 
					   WINDOW_WIDTH / 4, 
					   message, 
					   NUM_SIDES_LABEL_LENGTH, 
					   TEXTSIZE, 
					   WHITE, 
					   false, 
					   false);
	mainWindow.addComponent(numSidesLabel);

	GTextBox numSidesTextBox = {"numSidesTextBox", 
								 WINDOW_WIDTH / 2 - (NUMSIDES_TEXTBOX_WIDTH / 2), 
								 numSidesLabel.getYCoord() + GUI_SPACER, 
								 NUMSIDES_TEXTBOX_WIDTH, 
								 TEXTBOX_HEIGHT, 
								 true, 
								 true};
	mainWindow.addComponent(numSidesTextBox);

	GTexture calculateButtonTexture = {"button.png"};
	GButton calculateButton = {"calculateButton", 
							   calculateButtonTexture, 
							   0, 
							   //numSidesTextBox.getXCoord() + NUMSIDES_TEXTBOX_WIDTH + 10, 
							   10, 
							   //numSidesTextBox.getYCoord(), 
							   10, 
							   calculateButtonTexture.getFrameWidth(), 
							   calculateButtonTexture.getFrameHeight(), 
							   true, 
							   false};
	mainWindow.addComponent(calculateButton);

	int framesCounter = 0;
	Vector2 mouseLocation = {0.0f, 0.0f};
	SetTargetFPS(60);
	
	while(!WindowShouldClose())
	{
		// Update
		mainWindow.update(framesCounter, mouseLocation);

		// Draw
		BeginDrawing();
			mainWindow.draw(framesCounter);
		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}