#pragma once
#include "string.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Button
{
protected:
    //Top left position of button
    SDL_Point position;
    int width;
    int height;

public:
    bool inside;
    SDL_Rect srcRect, destRect;
    Button();
    Button(float xstart, float ystart, float xend, float yend, float w, float h);
    ~Button();
    void Render(SDL_Texture *);
    bool isOverMouse(int, int);
};