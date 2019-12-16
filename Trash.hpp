#include "GameObject.hpp"

class Trash : public GameObject
{

public:
    Trash(SDL_Texture *, float, float, float, float, float, double, float);
    //virtual ~Trash();
    void Update();
    // void Render();
};