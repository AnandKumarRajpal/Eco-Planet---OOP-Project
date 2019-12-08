#include "GameObject.hpp"

class RandomObj : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    RandomObj(SDL_Texture *, int, int, int, int, int, int, int);
    //virtual ~RandomObj();
    void Update();
    // void Render();
};