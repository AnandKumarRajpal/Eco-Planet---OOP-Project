#include "GameObject.hpp"

class Powers : public GameObject
{

public:
    Powers(SDL_Texture *, float, float, float, float, float, double, float);
    virtual ~Powers();
    void Update();
};