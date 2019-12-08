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
    SDL_Rect srcRect, destRect;

public:
    GameObject();
    GameObject(SDL_Texture *);
    GameObject(SDL_Texture *, int, int, int, int, float, int, int);
    virtual ~GameObject();
    void SetAlive(bool);
    bool GetAlive();
    int GetWidth() const;
    int GetHeight() const;
    float GetX() const;
    float GetY() const;
    virtual void Update() = 0;
    virtual void Render();
};