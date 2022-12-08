#ifndef G_TEXTBOX_H
#define G_TEXTBOX_H

#include "raylib.h"
#include "GComponent.h"
#include <string>

class GTextBox : public GComponent
{
    private:
    int xCoord = 0;
    int yCoord = 0;
    int width = 10;
    int height = 10;

    public:
    GTextBox(std::string newName, 
             int initXCoord, 
             int initYCoord, 
             int initWidth, 
             int initHeight) : 
             GComponent(newName), 
             xCoord(initXCoord), 
             yCoord(initYCoord), 
             width(initWidth), 
             height(initHeight){};
    ~GTextBox(){};
    void draw();
};

#endif