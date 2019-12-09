#include "Trash.hpp"

Trash::Trash(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, float w, float h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Trash constructor called" << std::endl;
}
void Trash::Update() {}