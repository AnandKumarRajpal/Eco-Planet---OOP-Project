/* #include "FosilFuels.hpp"

FossilFuel::FossilFuel(SDL_Texture *text, GameObject *object) : Enemies(text, object)
{
    //texture = Texture::loadTexture("2.png");
    std::cout << "Enemy Created";
}

void FossilFuel::Render()
{
    Uint32 ticks = SDL_GetTicks();
    int sprite = (ticks / 200) % 4;
    SDL_Rect srcrect = {sprite * 269, 0, 269, 218};
    if (ticks % 100 == 0 and destRect.x > 1)
    {
        std::cout << destRect.x << std::endl;
        destRect.x -= 5;
    }
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

void FossilFuel::Render(int)
{
}
 */