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
}