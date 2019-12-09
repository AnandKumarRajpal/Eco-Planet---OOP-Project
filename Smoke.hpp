#include "GameObject.hpp"

class Smoke : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    Smoke(SDL_Texture *, float, float, float, float, float, float, float);
    //virtual ~Smoke();
    void Update();
    // void Render();
};