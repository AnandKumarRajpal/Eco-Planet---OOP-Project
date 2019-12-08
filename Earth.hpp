#include "GameObject.hpp"

class Earth : public GameObject
{
    int life;
    SDL_Rect srcRect, destRect;

public:
    Earth(SDL_Texture *, int, int, int, int, int, int, int);
    //virtual ~Earth();
    void Update();
    // void Render();
};