
#include "Button.hpp"
#include "Game.hpp"

Button::Button() {}
Button::Button(float xstart, float ystart, float xend, float yend, float w, float h)
{
    //initializes positions 
    position.x = xend;
    position.y = yend;

    width = w;
    height = h;

    srcRect.x = xstart;
    srcRect.y = ystart;
    srcRect.h = height;
    srcRect.w = width;

    destRect.x = xend;
    destRect.y = yend;
    destRect.w = srcRect.w * 0.4;
    destRect.h = srcRect.h * 0.4;

    std::cout << "Button created" << std::endl;
}

void Button::Render(SDL_Texture *objTexture) 
{
    //renders object
    SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, 0.0, NULL, SDL_FLIP_NONE);
    std::cout << "Button rendered" << std::endl;
}
//detects click
bool Button::isOverMouse(int x, int y)
{
    //Mouse is left of the button
    if (x < position.x)
    {
        return false;
    }
    //Mouse is right of the button
    else if (x > position.x + destRect.w)
    {
        return false;
    }
    //Mouse above the button
    else if (y < position.y)
    {
        return false;
    }
    //Mouse below the button
    else if (y > position.y + destRect.h)
    {
        return false;
    }
    else
    {
        return true;
    }
}
Button::~Button() {}
