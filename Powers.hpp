#include "GameObject.hpp"

class Powers : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    Powers(SDL_Texture *, float, float, float, float, float, double, float);
    //virtual ~Powers();
    void Update();
    // void Render();
};