#ifndef G_TEXTURE_H
#define G_TEXTURE_H

#include "raylib.h"
#include <string>

class GTexture
{
    private:
    Texture2D image;
    float frameHeight;
    float frameWidth;
    int numFrames;

    public:
    GTexture(std::string imageFileName)
    {
        image = LoadTexture(imageFileName.c_str());
        frameHeight = (float)image.height / numFrames;
        frameWidth = (float)image.width;
    };
    ~GTexture(){ UnloadTexture(image); };
    float getFrameHeight(){ return frameHeight; };
    float getFrameWidth(){ return frameWidth; };
    int getNumFrames(){ return numFrames; };
    Texture2D get2DTexture(){ return image; };
};

#endif