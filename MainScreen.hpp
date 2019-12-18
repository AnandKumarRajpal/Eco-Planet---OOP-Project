#pragma once
#include "Screens.hpp"
#include "string.h"
#include <iostream>

class MainScreen : public Screens
{
    int scrollingOffset = 0;

public:
    MainScreen(SDL_Texture *, SDL_Texture *);
    virtual ~MainScreen();
    void Update();
};
