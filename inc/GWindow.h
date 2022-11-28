#ifndef G_WINDOW_H
#define G_WINDOW_H

#include "raylib.h"

class GWindow
{
    private:
    const int width;
    const int height;
    const Color bgcolor;
    const char* title;

    public:
    GWindow(int initWidth, int initHeight, Color initBgcolor, const char* initTitle);
    ~GWindow(){};
    void draw();
};

#endif