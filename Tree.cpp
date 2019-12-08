#include "Tree.hpp"

Tree::Tree(SDL_Texture *textureSheet, int xstart, int ystart, int xend, int yend, int scale, int w, int h)
    : GameObject(textureSheet, xstart, ystart, xend, yend, scale, w, h)
{
    std::cout << "Tree constructor called" << std::endl;
}
void Tree::Update()
{
}