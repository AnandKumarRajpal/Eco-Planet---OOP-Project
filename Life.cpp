#include "Life.hpp"

Life::Life(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, double w, float h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Life constructor called" << std::endl;
}
void Life::Update()
{
    //reduces life 
    Uint32 ticks = SDL_GetTicks();
    if (ticks % 20 == 0)
    {
        destRect.w -= 1;
        lifeValue = destRect.w;
        std::cout << lifeValue << std::endl;
    }
    this->Render();
}
