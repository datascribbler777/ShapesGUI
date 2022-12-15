#include "GButton.h"

GButton::GButton(std::string newName, 
             GTexture& initTexture, 
             int initButtonState, 
             int initXCoord, 
             int initYCoord, 
             int initWidth, 
             int initHeight, 
             bool focusableStatus, 
             bool hasFocusStatus) : 
             GComponent(newName, focusableStatus, hasFocusStatus), 
             buttonState(initButtonState), 
             xCoord(initXCoord), 
             yCoord(initYCoord), 
             width(initTexture.getFrameWidth()), 
             height(initTexture.getFrameHeight())
{
    GTexture* temp = &initTexture;
    buttonClicked = false;
    texture = temp;
    frameRectangle = {0, 
                      0,  
                      (float)width, 
                      (float)height};
    boundingBox = {(float)xCoord, 
                   (float)yCoord, 
                   (float)width, 
                   (float)height};
}

void GButton::draw(int& frameCounter)
{
    DrawTextureRec(texture->get2DTexture(), 
                   frameRectangle, 
                   (Vector2){xCoord, yCoord}, 
                   WHITE);
}

void GButton::update(int& frameCounter, Vector2 mouseLocation)
{
    buttonClicked = false;
    if(CheckCollisionPointRec(mouseLocation, boundingBox))
    {
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            buttonState = 2;
        }
        else
        {
            buttonState = 1;
        }

        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            buttonClicked = true;
        }
    }
    else
    {
        buttonState = 0;
    }

    if(buttonClicked)
    {
        // Button Action Code Here
    }

    // Calculate which frame of animiation button needs
    frameRectangle.y = buttonState * frameRectangle.height;
}