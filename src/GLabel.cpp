#include "GLabel.h"

GLabel::GLabel(std::string newName, 
               int initXCoord, 
               int initYCoord, 
               const char* initContent, 
               int initContentLength, 
               int initTextSize, 
               Color initColor, 
               bool focusableStatus, 
               bool hasFocusStatus) : 
               GComponent(newName, focusableStatus, hasFocusStatus), 
               xCoord(initXCoord), 
               yCoord(initYCoord), 
               content(initContent), 
               contentLength(initContentLength), 
               textSize(initTextSize), 
               textColor(initColor)
{
}

void GLabel::draw(int& framesCounter)
{
    DrawText(content, xCoord, yCoord, textSize, WHITE);
}

void GLabel::update(int& framesCounter)
{
    
}