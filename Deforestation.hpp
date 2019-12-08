#pragma once
#include <SDL.h>
#include "Enemies.hpp"

class Deforestation : public Enemies
{
    GameObject *obj_required_to_kill;

public:
    Deforestation(SDL_Texture *, GameObject *);
    ~Deforestation();
    void Render();
    void Hatchet();
};