#include "Tree.hpp"

Tree::Tree(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, double w, float h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Tree constructor called" << std::endl;
}
void Tree::Update()
{
    this->Render();
    if (destRect.x < -5)
    {
        destRect.x = 900;
    }
    destRect.x = destRect.x - 3;
}

Tree::~Tree(){}