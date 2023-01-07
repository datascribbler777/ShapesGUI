#include "GButton.h"

void GButton::update(int& framesCounter, Vector2 mouseCoords)
{
    if(CheckCollisionPointRec(mouseCoords, buttonBoundingBox))
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
            if(onClickFunction != nullptr)
            {
                onClickFunction();
            }
        }
    }
    else
    {
        buttonState = 0;
    }

    frameRectangle.y = buttonState * frameHeight;
}

void GButton::draw(int& framesCounter)
{
    DrawTextureRec(*texture, 
                frameRectangle, 
                (Vector2){buttonBoundingBox.x, buttonBoundingBox.y}, 
                WHITE);
}