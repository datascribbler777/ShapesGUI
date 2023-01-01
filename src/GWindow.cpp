#include "GWindow.h"

void GWindow::drawComponents(int& framesCounter)
{
    for(size_t i = 0; i < components.size(); i++)
    {
        components[i]->draw(framesCounter);
    }
}

GWindow::GWindow(int initWidth, int initHeight, Color initBgcolor, const char* initTitle) :
    width(initWidth), height(initHeight), bgcolor(initBgcolor), title(initTitle)
{
    InitWindow(width, height, title);
}

void GWindow::draw(int framesCounter)
{
    // Fill background with color
    ClearBackground(bgcolor);
    drawComponents(framesCounter);
}

void GWindow::addComponent(GComponent& newComponent)
{
    GComponent* temp = &newComponent;
    components.push_back(temp);
    if(components[components.size() - 1]->getFocusStatus())
    {
        setCurrentFocusIndex(components.size() - 1);
    }

}

/*
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
*/

void GWindow::setCurrentFocusIndex(int newIndex)
{
    currentFocusIndex = newIndex;
}

void GWindow::update(int& framesCounter, Vector2 mouseLocation)
{
    for(size_t i = 0; i < components.size(); i++)
    {
        components[i]->update(framesCounter, mouseLocation);
    }
}