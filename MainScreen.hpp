#pragma once
#include "Screen.h"
#include <SDL.h>

class MainScreen : public Screen
{
public:
    MainScreen();
    void Render(long int &frame, SDL_Renderer *);
    virtual ~gameScreen();
};
