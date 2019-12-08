#include "Life.hpp"

Life::Life(SDL_Texture *textureSheet, int xstart, int ystart, int xend, int yend, int scale, int w, int h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Life constructor called" << std::endl;
}
void Life::Update()
{
    destRect.w = destRect.w - 2;
    this->Render();
}
