#include <iostream>
#include <SDL_mixer.h>
#include <SDL.h>
using namespace std;
#pragma once

class Screen
{
private:
    int width;
    int height;

public:
    virtual void Render(long int &frame, SDL_Renderer *) = 0; //Render the Screen
    Screen();
    ~Screen();
};