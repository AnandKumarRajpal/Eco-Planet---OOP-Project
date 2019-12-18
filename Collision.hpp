#pragma once
#include "string.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
class Collision
{
public:
    Collision();
    ~Collision();
    bool check_collision(SDL_Rect, SDL_Rect);
};