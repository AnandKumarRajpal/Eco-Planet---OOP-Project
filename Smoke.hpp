#include "GameObject.hpp"

class Smoke : public GameObject
{

public:
    Smoke(SDL_Texture *, float, float, float, float, float, double, float);
    virtual ~Smoke();
    void Update();
};