#include "GameObject.hpp"

class Life : public GameObject
{
public:
    Life(SDL_Texture *, float, float, float, float, float, double, float);
    //virtual ~Life();
    void Update();
    // void Render();
};