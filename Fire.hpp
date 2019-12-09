#include "GameObject.hpp"

class Fire : public GameObject
{
    float life;
    SDL_Rect srcRect, destRect;

public:
    Fire(SDL_Texture *, float, float, float, float, float, float, float);
    //virtual ~Fire();
    void Update();
    // void Render();
};