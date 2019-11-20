#pragma once
#include "Screen.h"

class PauseScreen : public Screen
{
public:
    PauseScreen();
    void Render(long int &frame, SDL_Renderer *);
    virtual ~PauseScreen();
};