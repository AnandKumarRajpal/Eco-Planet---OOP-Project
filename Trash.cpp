#include "Trash.hpp"

Trash::Trash(SDL_Texture *textureSheet, int xstart, int ystart, int xend, int yend, int scale, int w, int h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Trash constructor called" << std::endl;
}
void Trash::Update() {}