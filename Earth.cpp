#include "Earth.hpp"

Earth::Earth(SDL_Texture *textureSheet, int xstart, int ystart, int xend, int yend, int scale, int w, int h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Earth constructor called" << std::endl;
}
void Earth::Update() {}