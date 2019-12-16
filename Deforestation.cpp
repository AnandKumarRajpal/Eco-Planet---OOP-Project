#include "Deforestation.hpp"

Deforestation::Deforestation(SDL_Texture *text, GameObject *object)
    : Enemies(text, object)
{
    //texture = Texture::loadTexture("1.png");
    //obj_required_to_kill = object;
    std::cout << "Enemy Created";
}

void Deforestation::Render()
{
    Uint32 ticks = SDL_GetTicks();
    int sprite = (ticks / 100) % 20;
    srcRect = {sprite * 339, 0, 339, 285};
    if (ticks % 10 == 0 and destRect.x > 1)
    {
        std::cout << destRect.x << std::endl;
        destRect.x -= 5;
    }
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

void Deforestation::Render(int y)
{
    Uint32 ticks = SDL_GetTicks();
    int sprite = (ticks / 50) % 20;
    srcRect = {sprite * 339, y, 339, 285};
    if (ticks % 10 == 0 and destRect.x > 1)
    {
        std::cout << destRect.x << std::endl;
        destRect.x -= 1;
    }
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}