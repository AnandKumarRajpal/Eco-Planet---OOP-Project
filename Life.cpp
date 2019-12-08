#include "Life.hpp"

Life::Life(SDL_Texture *textureSheet, int xstart, int ystart, int xend, int yend, int scale, int w, int h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Life constructor called" << std::endl;
}
void Life::Update()
{
    // // if (w.x < 0 || destRect.y < 0)
    // // {
    // //     destRect.x = 900;
    // //     destRect.y = 900;
    // // }
    // srcRect.w = srcRect.w - 30;
    // //width = width - 30;
    // this->Render();
}
