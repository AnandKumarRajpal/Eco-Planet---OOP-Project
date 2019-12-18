#pragma once
#include "Game.hpp"
#include "Texture.hpp"

class GameObject
{
protected:
    float xpos, ypos;
    int height, width;
    SDL_Point position;
    SDL_Texture *objTexture;

public:
    SDL_Rect srcRect, destRect;
    GameObject();
    GameObject(SDL_Texture *);
    GameObject(SDL_Texture *, float, float, float, float, float, double, float);
    virtual ~GameObject();
    int GetWidth() const;
    int GetHeight() const;
    float GetX() const;
    float GetY() const;
    void SetY(float);
    void operator=(float other);
    virtual void Update() = 0;
    virtual void Render();
    void UpdateObj();
};