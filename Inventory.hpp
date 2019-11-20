#include <SDL.h>
#include "Enemies.hpp"
#include "GameObjects.hpp"

class Inventory
{
    public:
        GameObjects ItemsCollected;
        IntensiveFarming();
        ~IntensiveFarming();
        void LandLord();
};