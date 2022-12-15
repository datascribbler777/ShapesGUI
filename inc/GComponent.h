#ifndef G_COMPONENT_H
#define G_COMPONENT_H

#include "raylib.h"
#include <string>

class GComponent
{
    private:
    std::string name;
    bool focusable = false;
    bool hasFocus = false;

    public:
    GComponent(std::string newName, bool focusableStatus, bool hasFocusStatus) : 
        name(newName), focusable(focusableStatus), hasFocus(hasFocusStatus){};
    virtual void draw(int& framesCounter) = 0;
    std::string getName(){ return name;};
    void setFocusable(bool newStatus){focusable = newStatus;};
    bool getFocusableStatus(){return focusable;};
    void setFocus(bool newStatus){hasFocus = newStatus;};
    bool getFocusStatus(){return hasFocus;};
    //virtual void update(int& framesCounter) = 0;
    virtual void update(int& framesCounter, Vector2 mouseLocation) = 0;
};

#endif