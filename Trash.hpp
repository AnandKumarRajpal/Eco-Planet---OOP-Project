#include "GameObject.hpp"

class Trash : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    Trash(SDL_Texture *, float, float, float, float, float, float, float);
    //virtual ~Trash();
    void Update();
    // void Render();
};