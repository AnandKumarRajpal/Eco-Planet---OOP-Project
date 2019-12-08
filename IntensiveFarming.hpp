#include <SDL.h>
#include "Enemies.hpp"

class IntensiveFarming : public Enemies
{
public:
    IntensiveFarming(SDL_Texture *, GameObject *);
    ~IntensiveFarming();
    void Render();
    void LandLord();
};