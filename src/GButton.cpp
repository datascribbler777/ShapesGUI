#include "GButton.h"

GButton::~GButton()
{
    UnloadTexture(buttonTexture);
}

void GButton::initializeTexture(std::string textureName)
{
    buttonTexture = LoadTexture(textureName.c_str());
}

void GButton::initializeFrame()
{
    // Have to cast here because raylib mixes int and float all over the place
    frameRectangle = {0, 0, (float)buttonTexture.width, (float)(buttonTexture.height / numFrames)};
}

void GButton::initBoundingBox(int initXCoord, int initYCoord)
{
    // Have to cast here because of raylib
    buttonBoundingBox = {(float)initXCoord, 
                         (float)initYCoord, 
                         (float)buttonTexture.width, 
                         (float)buttonTexture.height};
}

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

    frameRectangle.y = buttonState * frameRectangle.height;
}

void GButton::draw(int& framesCounter)
{
    DrawTextureRec(buttonTexture, 
                frameRectangle, 
                (Vector2){buttonBoundingBox.x, buttonBoundingBox.y}, 
                WHITE);
}