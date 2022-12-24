#include "raylib.h"
#include "GButton.h"
#include "GComponent.h"
#include "GWindow.h"
#include "GLabel.h"
#include "GTextBox.h"
#include <string>

// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int WINDOW_WIDTH = 540;
    int WINDOW_HEIGHT = 600;
    int NUM_FRAMES = 3;
    int NUM_SIDES_LABEL_LENGTH = 37;
    int TEXTSIZE = 20;
    int NUMSIDES_TEXTBOX_WIDTH = 225;
    int TEXTBOX_HEIGHT = 30;
    int GUI_SPACER = 30;
    Color BGCOLOR = {70, 119, 202, 255};
    const char message[NUM_SIDES_LABEL_LENGTH] = "How many sides does your shape have?";

    GWindow mainWindow = {WINDOW_WIDTH, WINDOW_HEIGHT, BGCOLOR, "Fooking Button Abstraction Test"};

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

	// The exe will need this same access to display the image properly, 
    // ie: exe must be able to see resource/button.png
    Texture2D buttonTexture = LoadTexture("resources\\button.png"); // Load button texture

    GButton myButton = {"howManySidesButton", 
                       true, 
                       false, 
                       buttonTexture, 
                       (float)buttonTexture.width, 
                       (float)buttonTexture.height / NUM_FRAMES, 
                       (float)numSidesTextBox.getXCoord() + NUMSIDES_TEXTBOX_WIDTH + 10.0f, 
                       (float)numSidesTextBox.getYCoord()};
    mainWindow.addComponent(myButton);  

	int framesCounter = 0;
	Vector2 mouseLocation = {0.0f, 0.0f};    

    SetTargetFPS(60);
    
    // Main game loop
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        mouseLocation = GetMousePosition();
        mainWindow.update(framesCounter, mouseLocation);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            mainWindow.draw(framesCounter);

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(buttonTexture);  // Unload button texture
    CloseWindow();          // Close window and OpenGL context

    return 0;
}