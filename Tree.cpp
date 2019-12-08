#include "Tree.hpp"

Tree::Tree(SDL_Texture *textureSheet, int xstart, int ystart, int xend, int yend, int scale, int w, int h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Tree constructor called" << std::endl;
}
void Tree::Update()
{
    if (destRect.x < 0 || destRect.y < 0)
    {
        destRect.x = 900;
        destRect.y = 900;
    }
    destRect.w--;
    this->Render();
}