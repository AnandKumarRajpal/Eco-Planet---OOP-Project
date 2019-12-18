#include "GameObject.hpp"

class Life : public GameObject
{
public:
    int lifeValue = 218;
    Life(SDL_Texture *, float, float, float, float, float, double, float);
    //virtual ~Life();
    void Update();
    // void Render();
};