#pragma once
#include "string.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RandomObj.hpp"

class Inventory
{
    RandomObj **lst = NULL;
    int stored;

public:
    Inventory();
    void append(RandomObj *);
    RandomObj *remove();
    ~Inventory();
};