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
    Button(int xstart, int ystart, int xend, int yend, int w, int h);
    ~Button();
    void Render(SDL_Texture *);
    bool isOverMouse(int, int);
    void handleEvents(SDL_Event *);
};