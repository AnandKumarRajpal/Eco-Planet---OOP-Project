#include <SDL.h>
#include "Enemies.hpp"

class Deforestation : public Enemies
{
    public:
        Deforestation();
        ~Deforestation();
        void Hatchet();
};