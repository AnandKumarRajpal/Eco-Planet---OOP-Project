#include "Deforestation.hpp"

Deforestation::Deforestation(SDL_Texture *text, SDL_Texture *attack_tex, GameObject *object)
    : Enemies(text, attack_tex, object)
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
    // if (ticks % 10 == 0 and destRect.x > 1)
    // {
    //     std::cout << destRect.x << std::endl;
    //     destRect.x -= 5;
    // }
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

void Deforestation::Render(int y)
{   
    Uint32 ticks = SDL_GetTicks();
    int sprite = (ticks / 50) % 20;
    int sprite_attack = (ticks / 50) % 8;
    srcRect = {sprite * 339, y, 339, 285};
    srcrect_attack = { sprite_attack * 50, 0, 50, 50};

    if (ticks % 10 == 0)
    {
        std::cout << dstrect_attack.x << std::endl;
        dstrect_attack.x -= 5;
    }

    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
    SDL_RenderCopy(Game::renderer, attack_tex, &srcrect_attack, &dstrect_attack);
}

void Deforestation::Hatchet()
{
    Uint32 ticks = SDL_GetTicks();
    int sprite_attack = (ticks / 50) % 8;
    srcrect_attack = { sprite_attack * 50, 0, 50, 50};
    if (ticks % 10 == 0)
    {
        std::cout << dstrect_attack.x << std::endl;
        dstrect_attack.x -= 5;
    }
    SDL_RenderCopy(Game::renderer, attack_tex, &srcrect_attack, &dstrect_attack);
}
Deforestation::~Deforestation(){}