#include "powers.hpp"

class Shield : public powers
{

public:
    Shield(LTexture *, float, float);
    void Render(SDL_Renderer *gRenderer);
    ~Shield();
};
