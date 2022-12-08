#include "GTextBox.h"

void GTextBox::draw()
{
    Rectangle temp = {xCoord, yCoord, width, height};
    DrawRectangleRec(temp, WHITE);
    DrawRectangleLines(xCoord, yCoord, width, height, BLACK);
}