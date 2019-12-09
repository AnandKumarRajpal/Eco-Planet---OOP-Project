#include "RandomObj.hpp"

RandomObj::RandomObj(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, float w, float h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "RandomObj constructor called" << std::endl;
}
void RandomObj::Update()
{
    if (destRect.x < 0 || destRect.y < 0)
    {
        destRect.x = 900;
        destRect.y = 900;
    }
    destRect.w--;
    this->Render();
}