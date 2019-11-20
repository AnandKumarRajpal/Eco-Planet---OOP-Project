#include <SDL.h>
#include "GameObjects.hpp"
class Enemies
{
    private:
        GameObjects obj_required_to_kill;
    public:
        Enemies();
        ~Enemies();
        virtual render(SDL_Renderer*)
        virtual void move();
        virtual bool check_death();
};