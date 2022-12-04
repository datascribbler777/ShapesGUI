#include "GWindow.h"

GWindow::GWindow(int initWidth, int initHeight, Color initBgcolor, const char* initTitle) :
    width(initWidth), height(initHeight), bgcolor(initBgcolor), title(initTitle)
{
    InitWindow(width, height, title);
}

void GWindow::draw()
{
    // Fill background with color
    ClearBackground(bgcolor);
    drawComponents();
}

GComponent* GWindow::getComponent(std::string componentName)
{
    GComponent* output = nullptr;
    for(size_t i = 0; i < components.size(); i++)
    {
        if(components[i]->getName() == componentName)
        {
            output = components[i];
        }
    }
    return output;
}

void GWindow::addComponent(GComponent& newComponent)
{
    GComponent* temp = &newComponent;
    components.push_back(temp);
}

void GWindow::drawComponents()
{
    for(size_t i = 0; i < components.size(); i++)
    {
        components[i]->draw();
    }
}