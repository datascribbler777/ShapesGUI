#include "GLabel.h"

GLabel::GLabel(int initXCoord, 
               int initYCoord, 
               const char* initContent, 
               int initContentLength, 
               int initTextSize, 
               Color initColor) : 
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
    DrawText(content, 50, 50, 20, WHITE);
}