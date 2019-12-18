#include "Screens.hpp"
class ScreenFactory //to implement Abstract factory design pattern
{
    Screens *scrns;

public:
    ScreenFactory();
    ~ScreenFactory();
    Screens *CreateScreen(std::string, SDL_Texture *, SDL_Texture *);
};