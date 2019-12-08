#include "IntensiveFarming.hpp"

IntensiveFarming::IntensiveFarming(SDL_Texture *text, GameObject *object)
    : Enemies(text, object)
{
    //texture = Texture::loadTexture("3.png");
    //obj_required_to_kill = object;
    std::cout << "Enemy Created";
}
void IntensiveFarming::Render()
{
    Uint32 ticks = SDL_GetTicks();
    Uint32 sprite = (ticks / 200) % 4;
    SDL_Rect srcrect = {sprite * 294, 0, 294, 275};
    if (ticks % 100 == 0 and dstrect.x > 1)
    {
        std::cout << dstrect.x << std::endl;
        dstrect.x -= 5;
    }
    SDL_RenderCopy(Game::renderer, texture, &srcrect, &dstrect);
}