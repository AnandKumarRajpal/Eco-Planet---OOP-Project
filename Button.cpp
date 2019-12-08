
#include "Button.hpp"
#include "Game.hpp"

Button::Button() {}
Button::Button(int xstart, int ystart, int xend, int yend, int w, int h)
{
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

void Button::Render(SDL_Texture *objTexture) //, int xstart, int ystart, int xend, int yend)
{

    SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, 0.0, NULL, SDL_FLIP_NONE);
    std::cout << "Button rendered" << std::endl;
}
bool Button::isOverMouse(int x, int y)
{
    //Mouse is left of the button
    if (x < position.x)
    {
        return false;
    }
    //Mouse is right of the button
    else if (x > position.x + width)
    {
        return false;
    }
    //Mouse above the button
    else if (y < position.y)
    {
        return false;
    }
    //Mouse below the button
    else if (y > position.y + height)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Button::handleEvents(SDL_Event *e)
{
    //If mouse event happened
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        inside = true;

        //Mouse is left of the button
        if (x < position.x)
        {
            inside = false;
        }
        //Mouse is right of the button
        else if (x > position.x + width)
        {
            inside = false;
        }
        //Mouse above the button
        else if (y < position.y)
        {
            inside = false;
        }
        //Mouse below the button
        else if (y > position.y + height)
        {
            inside = false;
        }
        else
        {
            inside = true;
        }
    }
}
Button::~Button() {}
