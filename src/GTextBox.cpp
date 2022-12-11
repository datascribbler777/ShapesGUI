#include "GTextBox.h"

void GTextBox::draw(int& framesCounter)
{
    Rectangle temp = {xCoord, yCoord, width, height};
    DrawRectangleRec(temp, WHITE);
    if(getFocusStatus())
    {
        DrawRectangleLines(xCoord, yCoord, width, height, RED);
    }
    else
    {
        DrawRectangleLines(xCoord, yCoord, width, height, BLACK);
    }

    // Draw what is currently in content of textbox
    DrawText(content, xCoord + 5, 
			 yCoord + 8, 
			 TEXTSIZE, 
			 BLACK);

    // Draw blinking cursor if this textbox has focus
    if(getFocusStatus())
    {
        if(contentCurrentSize < CONTENT_MAX_SIZE)
        {
            if(((framesCounter / 20) % 2) == 0)
            {
                DrawText("_", xCoord + 8 + MeasureText(content, TEXTSIZE), 
                            yCoord + 12, TEXTSIZE, BLACK);
            }
        }
    }
}

void GTextBox::update(int& framesCounter)
{
    // Handle typing in this text box
    if(getFocusStatus())
    {
        int keyPressed = GetCharPressed();
        while(keyPressed > 0)
        {
            // Only allow numeric input
            if((keyPressed >= 48) && (keyPressed <= 57) && (contentCurrentSize < CONTENT_MAX_SIZE))
            {
                content[contentCurrentSize] = (char)keyPressed;
                content[contentCurrentSize + 1] = '\0';
                contentCurrentSize++;
            }
            keyPressed = GetCharPressed();
        }
    }

    // Handle backspace to delete chars
    if(IsKeyPressed(KEY_BACKSPACE))
    {
        contentCurrentSize--;
        if(contentCurrentSize < 0)
        {
            contentCurrentSize = 0;
        }
        content[contentCurrentSize] = '\0';
    }

    // Tick counter to allow a blinking cursor
    if(getFocusStatus())
    {
        framesCounter++;
    }
    else
    {
        framesCounter = 0;
    }
}