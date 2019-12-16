#pragma once
#include <SDL.h>
#include "GameObject.hpp"

class Enemies : public GameObject
{
public:
    GameObject *obj_required_to_kill;
    SDL_Rect destRect = {600, 348, 136, 114};

    Enemies();
    Enemies(SDL_Texture *, GameObject *);
    ~Enemies();
    void Update();
    virtual void Render() = 0;
    virtual void Render(int) = 0;
    // virtual void move();
    // virtual bool check_death();
};