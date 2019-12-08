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
    Uint32 sprite = (ticks / 200) % 4;
    SDL_Rect srcrect = {sprite * 339, 0, 339, 285};
    if (ticks % 100 == 0 and dstrect.x > 1)
    {
        std::cout << dstrect.x << std::endl;
        dstrect.x -= 5;
    }
    SDL_RenderCopy(Game::renderer, texture, &srcrect, &dstrect);
}