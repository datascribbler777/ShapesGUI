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
    static const int TEXTSIZE = 20;
    //static const size_t CONTENT_MAX_SIZE = 3;
    static const int CONTENT_MAX_SIZE = 3;
    char content[CONTENT_MAX_SIZE + 1] = "\0";
    int contentCurrentSize = 0;

    public:
    GTextBox(std::string newName, 
             int initXCoord, 
             int initYCoord, 
             int initWidth, 
             int initHeight, 
             bool focusableStatus, 
             bool hasFocusStatus) : 
             GComponent(newName, focusableStatus, hasFocusStatus), 
             xCoord(initXCoord), 
             yCoord(initYCoord), 
             width(initWidth), 
             height(initHeight){};
    ~GTextBox(){};
    void draw(int& framesCounter);
    void update(int& framesCounter, Vector2 mouseLocation);
    int getXCoord(){ return xCoord; };
    int getYCoord(){ return yCoord; };
};

#endif