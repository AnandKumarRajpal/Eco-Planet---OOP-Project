#include "powers.hpp"

class TimePause : public powers
{

public:
    TimePause(LTexture *, float, float);
    void Render(SDL_Renderer *gRenderer);
    ~TimePause();
};