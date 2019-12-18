#pragma once
#include <SDL.h>
#include "Enemies.hpp"

class Deforestation : public Enemies
{
public:
    GameObject *obj_required_to_kill;
    Deforestation(SDL_Texture *, SDL_Texture *, GameObject *);
    virtual ~Deforestation();
    void Render();
    void Render(int);
    void Hatchet();
};