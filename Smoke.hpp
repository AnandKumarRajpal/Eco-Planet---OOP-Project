#include "GameObject.hpp"

class Smoke : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    Smoke(SDL_Texture *, int, int, int, int, int, int, int);
    //virtual ~Smoke();
    void Update();
    // void Render();
};