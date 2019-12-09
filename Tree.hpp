#include "GameObject.hpp"

class Tree : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    Tree(SDL_Texture *, float, float, float, float, float, float, float);
    //virtual ~Tree();
    void Update();
    // void Render();
};