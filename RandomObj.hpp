#pragma once
#include "GameObject.hpp"

class RandomObj : public GameObject
{
public:
    RandomObj(SDL_Texture *, float, float, float, float, float, double, float);
    virtual ~RandomObj();
    void Update();
};