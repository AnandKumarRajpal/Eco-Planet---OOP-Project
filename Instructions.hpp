#pragma once
#include "Screens.hpp"
#include "string.h"
#include <iostream>

class Instructions : public Screens
{
public:
    Instructions(SDL_Texture *, SDL_Texture *);
    //~Instructions();
    void Update();
    //void Render();
};
