#include "GameObject.hpp"

class Trash : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    Trash(SDL_Texture *, int, int, int, int, int, int, int);
    //virtual ~Trash();
    void Update();
    // void Render();
};