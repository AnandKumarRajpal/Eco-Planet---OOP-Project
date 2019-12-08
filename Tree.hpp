#include "GameObject.hpp"

class Tree : public GameObject
{
    SDL_Rect srcRect, destRect;

public:
    Tree(SDL_Texture *, int, int, int, int, int, int, int);
    //virtual ~Tree();
    void Update();
    // void Render();
};