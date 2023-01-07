// Program to create a GUI in C++ using the raylib gaming library
// Note: a copy of the resource folder must be visible to the .exe for
// textures to show up properly.

#include "raylib.h"
#include "GButton.h"
#include "GComponent.h"
#include "GWindow.h"
#include "GLabel.h"
#include "GTextBox.h"
#include <string>
#include <iostream>

// Namespacing these because raylib uses the same class names
namespace MSWin
{
    #include <windows.h>
    #include <shellapi.h>
}

// These 3 functions are to handle button clicks
// Function pointers to these functions are added in the GButton class
void numSidesButtonClick()
{
}

void howToButtonClick()
{

}

void gitHubButtonClick()
{
    MSWin::ShellExecuteW(0, 0, L"https://github.com/datascribbler777/ShapesGUI", 0, 0 , SW_SHOW );
}

// Program main entry point
//------------------------------------------------------------------------------------------
int main(void)
{
    int WINDOW_WIDTH = 540;
    int WINDOW_HEIGHT = 600;
    int NUM_SIDES_LABEL_LENGTH = 37;
    int TEXTSIZE = 20;
    int HEADER_TEXTSIZE = 30;
    int NUMSIDES_TEXTBOX_WIDTH = 225;
    int TEXTBOX_HEIGHT = 30;
    int GUI_SPACER = 30;
    int MAIN_LABEL_LENGTH = 24;
    Color BGCOLOR = {70, 119, 202, 255};
    const char message[NUM_SIDES_LABEL_LENGTH] = "How many sides does your shape have?";
    const char mainLabelText[MAIN_LABEL_LENGTH] = "IT'S HIP TO BE A SQUARE";

    // GUI Elements
    //--------------------------------------------------------------------------------------
    GWindow mainWindow = {WINDOW_WIDTH, WINDOW_HEIGHT, BGCOLOR, "Shapes GUI"};

    GLabel mainHeaderLabel("mainHeaderLabel", 
                           (WINDOW_WIDTH / 2) - (MeasureText(mainLabelText, HEADER_TEXTSIZE) / 2), 
                           2.5 * TEXTBOX_HEIGHT, 
                           mainLabelText, 
                           MAIN_LABEL_LENGTH, 
                           HEADER_TEXTSIZE, 
                           WHITE, 
                           false, 
                           false
                           );
    mainWindow.addComponent(mainHeaderLabel);

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

    GButton numSidesButton = {"numSidesButton", 
                           true, 
                           false, 
                           "resources\\button.png", 
                           numSidesTextBox.getXCoord() + NUMSIDES_TEXTBOX_WIDTH + 10, 
                           numSidesTextBox.getYCoord(),
                           numSidesButtonClick};
    mainWindow.addComponent(numSidesButton);

    GButton howToButton = {"howToTextureButton", 
                           true, 
                           false, 
                           "resources\\HowToButton.png", 
                           mainHeaderLabel.getXCoord(), 
                           TEXTBOX_HEIGHT, 
                           howToButtonClick};
    mainWindow.addComponent(howToButton);

    GButton githubButton = {"githubButton", 
                           true, 
                           false, 
                           "resources\\GitHubButton.png", 
                           mainHeaderLabel.getXCoord() + MeasureText(mainLabelText, HEADER_TEXTSIZE) - 
                                  93, 
                           TEXTBOX_HEIGHT, 
                           gitHubButtonClick};
    mainWindow.addComponent(githubButton);

	int framesCounter = 0;
	Vector2 mouseLocation = {0.0f, 0.0f};    

    SetTargetFPS(60);
    
    // Main loop
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

    CloseWindow();

    return 0;
}