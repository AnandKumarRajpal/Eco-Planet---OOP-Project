#pragma once
#include "Screens.hpp"
#include "string.h"
#include <iostream>

class MainScreen : public Screens
{
    //Smoke *smoke = NULL;
    int scrollingOffset = 0;

public:
    MainScreen(SDL_Texture *);
    ~MainScreen();
    void Update();

    //bool onMainScreen = false;
};
