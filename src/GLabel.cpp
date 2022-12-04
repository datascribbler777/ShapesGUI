#include "GLabel.h"

GLabel::GLabel(std::string newName, 
               int initXCoord, 
               int initYCoord, 
               const char* initContent, 
               int initContentLength, 
               int initTextSize, 
               Color initColor) : 
               GComponent(newName), 
               xCoord(initXCoord), 
               yCoord(initYCoord), 
               content(initContent), 
               contentLength(initContentLength), 
               textSize(initTextSize), 
               textColor(initColor)
{
}

void GLabel::draw()
{
    DrawText(content, xCoord, yCoord, textSize, WHITE);
}