#include "GameObject.hpp"

GameObject::GameObject() {}
GameObject::GameObject(SDL_Texture *tex)
{
    objTexture = tex;
    std::cout << "Game Object overloaded constructor called" << std::endl;
}
GameObject::GameObject(SDL_Texture *textureSheet, float xstart, float ystart, float xend, float yend, float scale, double w, float h)
{
    //initializes positions
    position.x = xend;
    position.y = yend;
    objTexture = textureSheet;
    srcRect = {int(xstart), int(ystart), int(w), int(h)};
    destRect.x = xend;
    destRect.y = yend;
    destRect.w = srcRect.w * scale;
    destRect.h = srcRect.h * scale;

    std::cout << "Game Object second overloaded constructor called" << std::endl;
}
int GameObject::GetWidth() const
{
    return width;
}

int GameObject::GetHeight() const
{
    return height;
}

float GameObject::GetX() const
{
    return xpos;
}
float GameObject::GetY() const
{
    return ypos;
}
void GameObject::SetY(float y)
{
    ypos = y;
}
void GameObject::Render()
{
    SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, 0.0, NULL, SDL_FLIP_NONE);
    std::cout << "Game Object render called" << std::endl;
}
void GameObject::UpdateObj()
{
    this->Render();
    destRect.x = destRect.x - 3;
}
void GameObject::operator=(float other)
{
    this->ypos = other;
}
GameObject::~GameObject() {}