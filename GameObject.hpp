#pragma once
#include "Game.hpp"
#include "Texture.hpp"

class GameObject
{
    int xpos, ypos, height, width;
    SDL_Point position;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;

public:
    GameObject();
    GameObject(SDL_Texture *, int, int, int, int, float, int, int);
    //~GameObject();
    virtual void Update() = 0;
    void Render();
};