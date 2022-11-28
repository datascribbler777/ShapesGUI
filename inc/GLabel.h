#ifndef G_LABEL_H
#define G_LABEL_H

#include "raylib.h"

class GLabel
{
    private:
    int xCoord;
    int yCoord;
    const char* content;
    int contentLength;
    int textSize;
    Color textColor;

    public:
    GLabel(int initXCoord, 
           int initYCoord, 
           const char* initContent, 
           int initContentLength, 
           int initTextSize, 
           Color initColor);
    ~GLabel(){};
    void draw();
};

#endif