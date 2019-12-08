#pragma once
#include "string.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Button.hpp"

class Screens
{
protected:
    SDL_Texture *screenTexture = NULL;
    SDL_Texture *btnTexture = NULL;
    Button **btns = NULL;
    int totalButtons = 0;

public:
    //currentScreen activeScreen;
    Screens(SDL_Texture *);
    Screens(SDL_Texture *, SDL_Texture *);
    virtual ~Screens();
    virtual void Update() = 0;
    void Render();
    void Render(int, int, int, int);
    virtual void handleEvents(SDL_Event *e) = 0;
};
