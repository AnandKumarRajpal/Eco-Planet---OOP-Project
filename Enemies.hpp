#pragma once
#include <SDL.h>
#include "GameObject.hpp"

class Enemies
{
protected:
    GameObject *obj_required_to_kill;
    SDL_Texture *texture = NULL;
    SDL_Rect dstrect = {600, 405, 41, 50};

public:
    Enemies();
    Enemies(SDL_Texture *, GameObject *);
    ~Enemies();
    virtual void Render() = 0;
    // virtual void move();
    // virtual bool check_death();
};