#ifndef G_BUTTON_H
#define G_BUTTON_H

#include "raylib.h"
#include "GComponent.h"
#include <string>

// Animated Button class
// Requires a texture with 3 frames for animation
class GButton : public GComponent
{
private:
    int numFrames = 3;
    Texture2D* texture;
    Texture2D buttonTexture;
    float frameWidth;
    float frameHeight;
    float xCoord;
    float yCoord;
    Rectangle frameRectangle;
    Rectangle buttonBoundingBox;
    int buttonState;
    // Function pointer to function to handle button clicks
    void (*onClickFunction)() = nullptr;

public:
    GButton(std::string initName, 
            bool initFocusableStatus, 
            bool initHasFocusStatus, 
            std::string textureFileName, 
            int initXCoord, 
            int initYCoord, 
            void(*incomingFunction)()) :
            GComponent(initName, initFocusableStatus, initHasFocusStatus),  
            buttonState{0}
    {
        onClickFunction = incomingFunction;
        initializeTexture(textureFileName);
        initializeFrame();
        initBoundingBox(initXCoord, initYCoord);
    }
    ~GButton();
    void initializeTexture(std::string textureName);
    void initializeFrame();
    void initBoundingBox(int initXCoord, int initYCoord);
    void update(int& framesCounter, Vector2 mouseCoords);
    void draw(int& framesCounter);
};

#endif