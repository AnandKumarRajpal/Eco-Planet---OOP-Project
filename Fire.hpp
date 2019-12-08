#include "GameObject.hpp"

class Fire : public GameObject
{
    int life;
    SDL_Rect srcRect, destRect;

public:
    Fire(SDL_Texture *, int, int, int, int, int, int, int);
    //virtual ~Fire();
    void Update();
    // void Render();
};