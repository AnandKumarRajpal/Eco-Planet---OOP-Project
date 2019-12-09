#pragma once
#include <SDL.h>
#include "GameObject.hpp"

class Enemies
{
public:
    GameObject *obj_required_to_kill;
    SDL_Texture *texture = NULL;
    SDL_Rect dstrect = {600, 348, 136, 114};
    SDL_Rect srcrect;
    // 339, 0, 339, 285
    Enemies();
    Enemies(SDL_Texture *, GameObject *);
    ~Enemies();
    virtual void Render() = 0;
    // virtual void move();
    // virtual bool check_death();
};