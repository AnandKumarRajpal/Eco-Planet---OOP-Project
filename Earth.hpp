#include "GameObject.hpp"

class Earth : public GameObject
{
    float life;
    SDL_Rect srcRect, destRect;

public:
    Earth(SDL_Texture *, float, float, float, float, float, float, float);
    //virtual ~Earth();
    void Update();
    // void Render();
};