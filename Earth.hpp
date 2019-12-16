#include "GameObject.hpp"

class Earth : public GameObject
{
    float life;

public:
    Earth(SDL_Texture *, float, float, float, float, float, double, float);
    //virtual ~Earth();
    void Update();
    // void Render();
};