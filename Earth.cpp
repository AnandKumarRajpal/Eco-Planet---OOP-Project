#include "Earth.hpp"

Earth::Earth(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, double w, float h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Earth constructor called" << std::endl;
}
void Earth::Update() {}
