/* #include "IntensiveFarming.hpp"

IntensiveFarming::IntensiveFarming(SDL_Texture *text, GameObject *object)
    : Enemies(text, object)
{
    //texture = Texture::loadTexture("3.png");
    std::cout << "Enemy Created";
}
void IntensiveFarming::Render()
{
    Uint32 ticks = SDL_GetTicks();
    int sprite = (ticks / 200) % 4;
    SDL_Rect srcrect = {sprite * 294, 0, 294, 275};
    if (ticks % 100 == 0 and destRect.x > 1)
    {
        std::cout << destRect.x << std::endl;
        destRect.x -= 5;
    }
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

void IntensiveFarming::Render(int)
{
} */