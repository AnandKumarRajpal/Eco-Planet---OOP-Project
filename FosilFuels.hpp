#include <SDL.h>
#pragma once
#include "Enemies.hpp"

class FossilFuel : public Enemies
{
public:
    FossilFuel(SDL_Texture *, GameObject *);
    ~FossilFuel();
    void Render();
    void FuelBomb();
};