#include "GameObject.hpp"

class RandomObj : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    RandomObj(SDL_Texture *, float, float, float, float, float, float, float);
    //virtual ~RandomObj();
    void Update();
    // void Render();
};