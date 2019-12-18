#pragma once
#include "Screens.hpp"
#include "string.h"
#include <iostream>

class StartScreen : public Screens
{
public:
    StartScreen(SDL_Texture *, SDL_Texture *);
    virtual ~StartScreen();
    void Update();
};
