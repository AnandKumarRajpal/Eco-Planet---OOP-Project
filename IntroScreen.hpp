#pragma once
#include "Screens.hpp"
#include "string.h"
#include <iostream>

class IntroScreen : public Screens
{
public:
    IntroScreen(SDL_Texture *, SDL_Texture *);
    virtual ~IntroScreen();
    void Update();
    //void Render();
};