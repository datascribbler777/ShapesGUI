#ifndef G_WINDOW_H
#define G_WINDOW_H

#include "raylib.h"
#include "GComponent.h"
#include <vector>
#include <string>

class GWindow
{
    private:
    const int width;
    const int height;
    const Color bgcolor;
    const char* title;
    std::vector<GComponent*> components;
    void drawComponents(int& framesCounter);
    int currentFocusIndex = -1;

    public:
    GWindow(int initWidth, int initHeight, Color initBgcolor, const char* initTitle);
    ~GWindow(){};
    void draw(int framesCounter);
    void addComponent(GComponent& newComponent);
    //GComponent* getComponent(std::string componentName);
    void setCurrentFocusIndex(int newIndex);
    void update(int& framesCounter);
};

#endif