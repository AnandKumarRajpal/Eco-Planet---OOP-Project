#include "RandomObj.hpp"

RandomObj::RandomObj(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, double w, float h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "RandomObj constructor called" << std::endl;
}
void RandomObj::Update()
{
    this->Render();
    destRect.x = destRect.x + 3;
}

RandomObj::~RandomObj(){}