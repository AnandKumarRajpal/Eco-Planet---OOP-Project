#pragma once
#include "Screen.h"

class IntoductionScreen : public Screen
{
public:
    IntoductionScreen();
    void Render(long int &frame, SDL_Renderer *);
    virtual ~IntoductionScreen();
};