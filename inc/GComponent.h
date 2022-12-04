#ifndef G_COMPONENT_H
#define G_COMPONENT_H

#include "raylib.h"
#include <string>

class GComponent
{
    private:
    std::string name;

    public:
    GComponent(std::string newName) : name(newName){};
    virtual void draw() = 0;
    std::string getName(){ return name;};
};

#endif