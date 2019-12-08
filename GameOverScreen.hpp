#pragma once
#include "Screens.hpp"
#include "string.h"
#include <iostream>

class GameOverScreen : public Screens
{
public:
    GameOverScreen(SDL_Texture *, SDL_Texture *);
    //~GameOverScreen();
    void Update();
    //void Render();
};
