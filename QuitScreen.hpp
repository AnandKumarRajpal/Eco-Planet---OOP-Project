#pragma once
#include "Screen.h"

class QuitScreen : public Screen
{
public:
    QuitScreen();
    void Render(long int &frame, SDL_Renderer *);
    virtual ~quitScreen();
};