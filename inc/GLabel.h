#ifndef G_LABEL_H
#define G_LABEL_H

#include "raylib.h"
#include "GComponent.h"
#include <string>

class GLabel : public GComponent
{
    private:
    int xCoord = 0;
    int yCoord = 0;
    const char* content;
    int contentLength = 1;
    int textSize = 10;
    Color textColor = BLACK;

    public:
    GLabel(std::string newName, 
           int initXCoord, 
           int initYCoord, 
           const char* initContent, 
           int initContentLength, 
           int initTextSize, 
           Color initColor, 
           bool focusableStatus, 
           bool hasFocusStatus);
    ~GLabel(){};
    void draw(int& framesCounter);
    int getYCoord(){return yCoord;};
    void update(int& framesCounter);
};

#endif