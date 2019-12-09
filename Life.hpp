#include "GameObject.hpp"

class Life : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    Life(SDL_Texture *, float, float, float, float, float, float, float);
    //virtual ~Life();
    void Update();
    // void Render();
};