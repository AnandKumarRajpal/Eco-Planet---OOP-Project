#include "GameObject.hpp"

class Life : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    Life(SDL_Texture *, int, int, int, int, int, int, int);
    //virtual ~Life();
    void Update();
    // void Render();
};