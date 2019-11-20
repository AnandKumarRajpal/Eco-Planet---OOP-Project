#include <SDL.h>
#include "Enemies.hpp"

class IntensiveFarming : public Enemies
{
    public:
        IntensiveFarming();
        ~IntensiveFarming();
        void LandLord();
};