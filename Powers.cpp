#include "Powers.hpp"

Powers::Powers(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, double w, float h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Powers constructor called" << std::endl;
}
void Powers::Update() {}
Powers::~Powers(){}