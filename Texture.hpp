
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string.h>
#include "Game.hpp"

class Texture
{
public:
    static SDL_Texture *loadTexture(std::string filename);
};
