#include "Smoke.hpp"

Smoke::Smoke(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, float w, float h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Smoke constructor called" << std::endl;
}
void Smoke::Update() {}