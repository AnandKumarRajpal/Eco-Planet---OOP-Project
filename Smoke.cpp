#include "Smoke.hpp"

Smoke::Smoke(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, double w, float h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Smoke constructor called" << std::endl;
}
void Smoke::Update() 
{
    this->Render();
    if (destRect.x < -5)
    {
        destRect.x = 900;
    }
    destRect.x = destRect.x - 5;
}
Smoke::~Smoke(){}