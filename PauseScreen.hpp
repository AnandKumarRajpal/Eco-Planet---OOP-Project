#pragma once
#include "Screens.hpp"
#include "string.h"
#include <iostream>

class PauseScreen : public Screens
{
public:
    PauseScreen(SDL_Texture *, SDL_Texture *);
    ~PauseScreen();
    void Update();
    //bool onPauseScreen = false;
};
