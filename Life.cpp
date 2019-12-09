#include "Life.hpp"

Life::Life(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, float w, float h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Life constructor called" << std::endl;
}
void Life::Update()
{
    destRect.w = destRect.w - 2;
    this->Render();
}
