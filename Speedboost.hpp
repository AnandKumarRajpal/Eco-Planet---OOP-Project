#include "powers.hpp"

class Speedboost : public powers
{

public:
    Speedboost(LTexture *, float, float);
    void Render(SDL_Renderer *gRenderer);
    ~Speedboost();
};