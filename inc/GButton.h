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
    float frameWidth;
    float frameHeight;
    float xCoord;
    float yCoord;
    Rectangle frameRectangle;
    Rectangle buttonBoundingBox;
    int buttonState;
    // Function pointer to function to handle button clicks
    void (*onClickFunction)();

public:
    GButton(std::string initName, 
           bool initFocusableStatus, 
           bool initHasFocusStatus, 
           Texture2D& initTexture, 
           float initFrameWidth, 
           float initFrameHeight, 
           float initXCoord, 
           float initYCoord, 
           void(*onClickFunction)()) :
           GComponent(initName, initFocusableStatus, initHasFocusStatus)
    {
        texture = &initTexture;
        frameWidth = initFrameWidth;
        frameHeight = (initFrameHeight);
        frameRectangle = {0, 0, initFrameWidth, initFrameHeight};
        xCoord = initXCoord;
        yCoord = initYCoord;
        buttonBoundingBox = {initXCoord, 
                             initYCoord, 
                             initFrameWidth, 
                             initFrameHeight};
        buttonState = 0;
        onClickFunction = onClickFunction;
    };
    ~GButton(){};
    void update(int& framesCounter, Vector2 mouseCoords);
    void draw(int& framesCounter);
};

#endif