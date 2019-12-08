#pragma once
#include "Game.hpp"
#include "Texture.hpp"

class GameObject
{
protected:
    int xpos, ypos, height;
    SDL_Point position;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;

public:
    int width;
    GameObject();
    GameObject(SDL_Texture *, int, int, int, int, float, int, int);
    //~GameObject();
    virtual void Update() = 0;
    void Render();
};