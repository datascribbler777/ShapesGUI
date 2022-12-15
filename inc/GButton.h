#ifndef G_BUTTON_H
#define G_BUTTON_H

#include "raylib.h"
#include "GComponent.h"
#include "GTexture.h"
#include <string>

// Animated Button class
// Requires a texture with 3 frames for animation
class GButton : public GComponent
{
    private:
    GTexture* texture;
    Rectangle frameRectangle;
    Rectangle boundingBox;
    int buttonState;
    bool buttonClicked;
    int xCoord = 0;
    int yCoord = 0;
    int width = 10;
    int height = 10;

    public:
    GButton(std::string newName, 
             GTexture& initTexture, 
             int initButtonState, 
             int initXCoord, 
             int initYCoord, 
             int initWidth, 
             int initHeight, 
             bool focusableStatus, 
             bool hasFocusStatus);
    ~GButton(){};
    void draw(int& framesCounter);
    void update(int& framesCounter, Vector2 mouseLocation);
};

#endif