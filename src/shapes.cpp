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
    int NUM_FRAMES = 3;
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

	// The exe will need this same access to display the image properly, 
    // ie: exe must be able to see resource/button.png
    Texture2D buttonTexture = LoadTexture("resources\\button.png"); // Load button texture
    GButton numSidesButton = {"numSidesButton", 
                       true, 
                       false, 
                       buttonTexture, 
                       (float)buttonTexture.width, 
                       (float)buttonTexture.height / NUM_FRAMES, 
                       (float)numSidesTextBox.getXCoord() + NUMSIDES_TEXTBOX_WIDTH + 10.0f, 
                       (float)numSidesTextBox.getYCoord(), 
                       numSidesButtonClick};
    mainWindow.addComponent(numSidesButton);  

    Texture2D howToTexture = LoadTexture("resources\\HowToButton.png");
    GButton howToButton = {"howToTexture", 
                           true,
                           false,
                           howToTexture, 
                           (float)howToTexture.width,
                           (float)howToTexture.height / NUM_FRAMES, 
                           (float)mainHeaderLabel.getXCoord(), 
                           (float)TEXTBOX_HEIGHT, 
                           howToButtonClick};
    mainWindow.addComponent(howToButton);

    Texture2D githubTexture = LoadTexture("resources\\GitHubButton.png");
    GButton githubButton = {"githubTexture", 
                           true,
                           false,
                           githubTexture, 
                           (float)githubTexture.width,
                           (float)githubTexture.height / NUM_FRAMES, 
                           (float)mainHeaderLabel.getXCoord() + MeasureText(mainLabelText, HEADER_TEXTSIZE) - 
                                  githubTexture.width, 
                           (float)TEXTBOX_HEIGHT, 
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

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(buttonTexture);
    UnloadTexture(howToTexture);
    UnloadTexture(githubTexture);
    CloseWindow();

    return 0;
}